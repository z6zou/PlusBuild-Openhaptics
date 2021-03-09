/*=========================================================================

  Program:   OpenIGTLink Library -- Example for Thread (Single Method)
  Module:    $RCSfile: itkImage.h,v $
  Language:  C++
  Date:      $Date: 2008/01/13 19:48:38 $
  Version:   $Revision: 1.142 $

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include "igtlMultiThreader.h"
#include "igtlOSUtil.h"


typedef struct {
  int   nloop;
  igtl::MutexLock::Pointer glock;
} ThreadData;


#define NUM_THREADS  4


void* ThreadFunction(void* ptr)
{
  //------------------------------------------------------------
  // Get thread information
  igtl::MultiThreader::ThreadInfo* info = 
    static_cast<igtl::MultiThreader::ThreadInfo*>(ptr);

  int id      = info->ThreadID;
  int nThread = info->NumberOfThreads;
  ThreadData* data = static_cast<ThreadData*>(info->UserData);

  //------------------------------------------------------------
  // Get user data
  int nloop = data->nloop;
  igtl::MutexLock::Pointer glock = data->glock;

  long interval = (id + 1) * 100; // (ms)

  //------------------------------------------------------------
  // Loop
  for (int i = 0; i < nloop; i ++)
    {
    glock->Lock();
    std::cerr << "Thread #" << id << ": counter = " << i << std::endl;
    glock->Unlock();
    igtl::Sleep(interval);
    }

  glock->Lock();
  std::cerr << "Thread #" << id << ": end." << std::endl;
  glock->Unlock();
  
  return NULL;
}


int main(int argc, char * argv [] )
{
  //------------------------------------------------------------
  // Set up thread and mutex cleasses
  igtl::MultiThreader::Pointer threader = igtl::MultiThreader::New();
  igtl::MutexLock::Pointer glock = igtl::MutexLock::New();

  //------------------------------------------------------------
  // Set user data
  ThreadData td;
  td.nloop = 20;
  td.glock = glock;
  
  //------------------------------------------------------------
  // Set multiple methods as threads
  threader->SetNumberOfThreads(NUM_THREADS);
  threader->SetSingleMethod((igtl::ThreadFunctionType) &ThreadFunction, &td);

  //------------------------------------------------------------
  // Start threads -- the main thread waits until all threads return.
  std::cerr << "Starting threads ...." << std::endl;
  threader->SingleMethodExecute();
  std::cerr << "Theads stopped ...." << std::endl;

  return 0;
}





