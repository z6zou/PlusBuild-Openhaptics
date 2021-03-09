/*=========================================================================

  Program:   OpenIGTLink -- Example for Trajectory message
  Language:  C++

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include <iostream>
#include <math.h>
#include <cstdlib>

#include "igtlOSUtil.h"
#include "igtlTrajectoryMessage.h"
#include "igtlServerSocket.h"

int main(int argc, char* argv[])
{
  //------------------------------------------------------------
  // Parse Arguments

  if (argc != 2) // check number of arguments
    {
    // If not correct, print usage
    std::cerr << "Usage: " << argv[0] << " <port> <fps>"    << std::endl;
    std::cerr << "    <port>     : Port # (18944 in Slicer default)"   << std::endl;
    exit(0);
    }

  int    port     = atoi(argv[1]);

  igtl::ServerSocket::Pointer serverSocket;
  serverSocket = igtl::ServerSocket::New();
  int r = serverSocket->CreateServer(port);

  if (r < 0)
    {
    std::cerr << "Cannot create a server socket." << std::endl;
    exit(0);
    }

  igtl::Socket::Pointer socket;

  while (1)
    {
    //------------------------------------------------------------
    // Waiting for Connection
    socket = serverSocket->WaitForConnection(1000);
    
    if (socket.IsNotNull()) // if client connected
      {
      
      //---------------------------
      // Create a trajectory message
      igtl::TrajectoryMessage::Pointer trajectoryMsg;
      trajectoryMsg = igtl::TrajectoryMessage::New();
      trajectoryMsg->SetDeviceName("TrajectorySender");
      
      //---------------------------
      // Create 1st trajectory
      igtl::TrajectoryElement::Pointer trajectory0;
      trajectory0 = igtl::TrajectoryElement::New();
      trajectory0->SetName("TRAJECTORY_0");
      trajectory0->SetGroupName("GROUP_0");
      trajectory0->SetRGBA(0xFF, 0x00, 0x00, 0xFF);
      trajectory0->SetEntryPosition(10.0, 20.0, 30.0);
      trajectory0->SetTargetPosition(20.0, 20.0, 40.0);
      trajectory0->SetRadius(15.0);
      trajectory0->SetOwner("IMAGE_0");
      
      //---------------------------
      // Create 2nd trajectory
      igtl::TrajectoryElement::Pointer trajectory1;
      trajectory1 = igtl::TrajectoryElement::New();
      trajectory1->SetName("TRAJECTORY_1");
      trajectory1->SetGroupName("GROUP_0");
      trajectory1->SetRGBA(0x00, 0xFF, 0x00, 0xFF);
      trajectory1->SetEntryPosition(40.0, 50.0, 60.0);
      trajectory1->SetTargetPosition(20.0, 30.0, 10.0);
      trajectory1->SetRadius(45.0);
      trajectory1->SetOwner("IMAGE_0");
      
      //---------------------------
      // Create 3rd trajectory
      igtl::TrajectoryElement::Pointer trajectory2;
      trajectory2 = igtl::TrajectoryElement::New();
      trajectory2->SetName("TRAJECTORY_2");
      trajectory2->SetGroupName("GROUP_0");
      trajectory2->SetRGBA(0x00, 0x00, 0xFF, 0xFF);
      trajectory2->SetEntryPosition(70.0, 80.0, 90.0);
      trajectory2->SetTargetPosition(10.0, 40.0, 20.0);
      trajectory2->SetRadius(75.0);
      trajectory2->SetOwner("IMAGE_0");
      
      //---------------------------
      // Pack into the trajectory message
      trajectoryMsg->AddTrajectoryElement(trajectory0);
      trajectoryMsg->AddTrajectoryElement(trajectory1);
      trajectoryMsg->AddTrajectoryElement(trajectory2);
      trajectoryMsg->Pack();
      
      //---------------------------
      // Send
      socket->Send(trajectoryMsg->GetPackPointer(), trajectoryMsg->GetPackSize());
      }

    //------------------------------------------------------------
    // Close connection (The example code never reachs to this section ...)
    }

  socket->CloseSocket();

}


