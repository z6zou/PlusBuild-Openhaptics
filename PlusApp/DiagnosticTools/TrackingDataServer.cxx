/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#include "PlusConfigure.h"

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <cstring>

#include "igtlImageMessage.h"
#include "igtlMessageHeader.h"
#include "igtlMultiThreader.h"
#include "igtlOSUtil.h"
#include "igtlServerSocket.h"
#include "igtlTrackingDataMessage.h"
#include "vtkPlusIgtlMessageFactory.h"
#include "vtksys/CommandLineArguments.hxx"


void* ThreadFunction(void* ptr);
int   SendTrackingData(igtl::Socket::Pointer& socket, igtl::TrackingDataMessage::Pointer& trackingMsg);
void  GetRandomTestMatrix(igtl::Matrix4x4& matrix, float phi, float theta);

typedef struct
{
  int   nloop;
  igtl::MutexLock::Pointer glock;
  igtl::Socket::Pointer socket;
  int   interval;
  int   stop;
} ThreadData;

int main(int argc, char* argv[])
{
  bool printHelp(false);
  int verboseLevel = vtkPlusLogger::LOG_LEVEL_UNDEFINED;
  int port = 18944;

  vtksys::CommandLineArguments args;
  args.Initialize(argc, argv);

  args.AddArgument("--help", vtksys::CommandLineArguments::NO_ARGUMENT, &printHelp, "Print this help.");
  args.AddArgument("--verbose", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &verboseLevel, "Verbose level (1=error only, 2=warning, 3=info, 4=debug, 5=trace)");
  args.AddArgument("--port", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &port, "Server port number");

  if (!args.Parse())
  {
    std::cerr << "Problem parsing arguments" << std::endl;
    std::cout << "Help: " << args.GetHelp() << std::endl;
    exit(EXIT_FAILURE);
  }

  if (printHelp)
  {
    std::cout << args.GetHelp() << std::endl;
    exit(EXIT_SUCCESS);
  }

  /*! igtl Factory for message sending */
  vtkSmartPointer<vtkPlusIgtlMessageFactory> IgtlMessageFactory;

  vtkPlusLogger::Instance()->SetLogLevel(verboseLevel);

  igtl::ServerSocket::Pointer serverSocket;
  serverSocket = igtl::ServerSocket::New();
  int r = serverSocket->CreateServer(port);

  if (r < 0)
  {
    std::cerr << "Cannot create a server socket." << std::endl;
    exit(0);
  }

  igtl::MultiThreader::Pointer threader = igtl::MultiThreader::New();
  igtl::MutexLock::Pointer glock = igtl::MutexLock::New();
  ThreadData td;

  while (1)
  {
    //------------------------------------------------------------
    // Waiting for Connection
    int threadID = -1;
    igtl::Socket::Pointer socket;
    socket = serverSocket->WaitForConnection(1000);

    if (socket.IsNotNull()) // if client connected
    {
      std::cerr << "A client is connected." << std::endl;

      // Create a message buffer to receive header
      igtl::MessageHeader::Pointer headerMsg = IgtlMessageFactory->CreateHeaderMessage(IGTL_HEADER_VERSION_1);

      //------------------------------------------------------------
      // loop
      while (true)
      {
        // Receive generic header from the socket
        int rs = socket->Receive(headerMsg->GetBufferPointer(), headerMsg->GetBufferSize());
        if (rs == 0)
        {
          if (threadID >= 0)
          {
            td.stop = 1;
            threader->TerminateThread(threadID);
            threadID = -1;
          }
          std::cerr << "Disconnecting the client." << std::endl;
          td.socket = NULL;  // VERY IMPORTANT. Completely remove the instance.
          socket->CloseSocket();
          break;
        }
        if (rs != headerMsg->GetBufferSize())
        {
          continue;
        }

        // Deserialize the header
        headerMsg->Unpack();

        // Check data type and receive data body
        igtl::MessageBase::Pointer bodyMsg = IgtlMessageFactory->CreateReceiveMessage(headerMsg);
        if (bodyMsg.IsNull())
        {
          continue;
        }
        if (typeid(*bodyMsg) == typeid(igtl::StartTrackingDataMessage))
        {
          std::cerr << "Received a STT_TDATA message." << std::endl;

          igtl::StartTrackingDataMessage::Pointer startTracking;
          startTracking = igtl::StartTrackingDataMessage::New();
          startTracking->SetMessageHeader(headerMsg);
          startTracking->AllocateBuffer();

          int r2 = socket->Receive(startTracking->GetBufferBodyPointer(), startTracking->GetBufferBodySize());
          int c = startTracking->Unpack(1);
          if (c & igtl::MessageHeader::UNPACK_BODY) // if CRC check is OK
          {
            td.interval = startTracking->GetResolution();
            td.glock    = glock;
            td.socket   = socket;
            td.stop     = 0;
            threadID    = threader->SpawnThread((igtl::ThreadFunctionType) &ThreadFunction, &td);
          }
        }
        else if (typeid(*bodyMsg) == typeid(igtl::StopTrackingDataMessage))
        {
          socket->Skip(headerMsg->GetBodySizeToRead(), 0);
          std::cerr << "Received a STP_TDATA message." << std::endl;
          if (threadID >= 0)
          {
            td.stop  = 1;
            threader->TerminateThread(threadID);
            threadID = -1;
            std::cerr << "Disconnecting the client." << std::endl;
            td.socket = NULL;  // VERY IMPORTANT. Completely remove the instance.
            socket->CloseSocket();
          }
          break;
        }
        else
        {
          std::cerr << "Receiving : " << headerMsg->GetMessageType() << std::endl;
          socket->Skip(headerMsg->GetBodySizeToRead(), 0);
        }
      }
    }
  }

  //------------------------------------------------------------
  // Close connection (The example code never reaches to this section ...)
  serverSocket->CloseSocket();
}

void* ThreadFunction(void* ptr)
{
  //------------------------------------------------------------
  // Get thread information
  igtl::MultiThreader::ThreadInfo* info =
    static_cast<igtl::MultiThreader::ThreadInfo*>(ptr);

  ThreadData* td = static_cast<ThreadData*>(info->UserData);

  //------------------------------------------------------------
  // Get user data
  igtl::MutexLock::Pointer glock = td->glock;
  long interval = td->interval;
  std::cerr << "Interval = " << interval << " (ms)" << std::endl;

  igtl::Socket::Pointer& socket = td->socket;

  //------------------------------------------------------------
  // Allocate TrackingData Message Class
  //
  // NOTE: TrackingDataElement class instances are allocated
  //       before the loop starts to avoid reallocation
  //       in each image transfer.

  igtl::TrackingDataMessage::Pointer trackingMsg;
  trackingMsg = igtl::TrackingDataMessage::New();
  trackingMsg->SetDeviceName("Tracker");

  igtl::TrackingDataElement::Pointer trackElement0;
  trackElement0 = igtl::TrackingDataElement::New();
  trackElement0->SetName("Probe");
  trackElement0->SetType(igtl::TrackingDataElement::TYPE_6D);

  igtl::TrackingDataElement::Pointer trackElement1;
  trackElement1 = igtl::TrackingDataElement::New();
  trackElement1->SetName("Reference");
  trackElement1->SetType(igtl::TrackingDataElement::TYPE_6D);

  igtl::TrackingDataElement::Pointer trackElement2;
  trackElement2 = igtl::TrackingDataElement::New();
  trackElement2->SetName("Stylus");
  trackElement2->SetType(igtl::TrackingDataElement::TYPE_6D);

  trackingMsg->AddTrackingDataElement(trackElement0);
  trackingMsg->AddTrackingDataElement(trackElement1);
  trackingMsg->AddTrackingDataElement(trackElement2);

  //------------------------------------------------------------
  // Loop
  while (!td->stop)
  {
    glock->Lock();
    SendTrackingData(socket, trackingMsg);
    glock->Unlock();
    igtl::Sleep(interval);
  }

  return NULL;
}


int SendTrackingData(igtl::Socket::Pointer& socket, igtl::TrackingDataMessage::Pointer& trackingMsg)
{

  static float phi0   = 0.0;
  static float theta0 = 0.0;
  static float phi1   = 1.1;
  static float theta1 = 1.1;
  static float phi2   = 2.5;
  static float theta2 = 2.5;

  igtl::Matrix4x4 matrix;
  igtl::TrackingDataElement::Pointer ptr;

  // Channel 0
  trackingMsg->GetTrackingDataElement(0, ptr);
  GetRandomTestMatrix(matrix, phi0, theta0);
  ptr->SetMatrix(matrix);

  // Channel 1
  trackingMsg->GetTrackingDataElement(1, ptr);
  GetRandomTestMatrix(matrix, phi1, theta1);
  ptr->SetMatrix(matrix);

  // Channel 2
  trackingMsg->GetTrackingDataElement(2, ptr);
  GetRandomTestMatrix(matrix, phi2, theta2);
  ptr->SetMatrix(matrix);

  trackingMsg->Pack();
  socket->Send(trackingMsg->GetBufferPointer(), trackingMsg->GetBufferSize());

  phi0 += 0.1;
  phi1 += 0.2;
  phi2 += 0.3;
  theta0 += 0.2;
  theta1 += 0.1;
  theta2 += 0.05;

  return 0;
}



//------------------------------------------------------------
// Function to generate random matrix.
void GetRandomTestMatrix(igtl::Matrix4x4& matrix, float phi, float theta)
{
  float position[3];
  float orientation[4];

  // random position
  position[0] = 50.0 * cos(phi);
  position[1] = 50.0 * sin(phi);
  position[2] = 50.0 * cos(phi);
  phi = phi + 0.2;

  // random orientation
  orientation[0] = 0.0;
  orientation[1] = 0.6666666666 * cos(theta);
  orientation[2] = 0.577350269189626;
  orientation[3] = 0.6666666666 * sin(theta);
  theta = theta + 0.1;

  //igtl::Matrix4x4 matrix;
  igtl::QuaternionToMatrix(orientation, matrix);

  matrix[0][3] = position[0];
  matrix[1][3] = position[1];
  matrix[2][3] = position[2];

  igtl::PrintMatrix(matrix);
}


