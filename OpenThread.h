
#ifndef FINAL_PROJECT_SECOND_OpenThread_H
#define FINAL_PROJECT_SECOND_OpenThread_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <vector>
#include <pthread.h>
#include "ClientHandler.h"

enum which_server_communication{SerialServer, ParallelServer};


void* run_solver_serial(void* arg) ;
void* run_solver_parallel(void* arg) ;
void* run_in_parallel(void* arg) ;

class OpenThread {

  public:
    pthread_t open_thread(int port, ClientHandler* c_h, int server_client_handle) ;
    ~OpenThread();
  
};

// This struct is used for handling a client/s in a diferent thread.

//struct solver_struct {
//    int port ;
//    ClientHandler* c_h ;
//
//};

// This struct is used to run from a different thread when the server is run in parallel.

struct parallel_struct {
    ClientHandler* c_h ;
    int sock_fd ;
    bool *is_thread_finished ;

};


#endif //FINAL_PROJECT_SECOND_OpenThread_H
