
#ifndef FINAL_PROJECT_SECOND_ClientHandler_H
#define FINAL_PROJECT_SECOND_ClientHandler_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <string>
#include "Solver.h"
#include "OpenSocket.h"
#include "SearchableUtility.h"

using namespace std ;

class ClientHandler {

    public:
        virtual void handle_client(int sock_fd) = 0 ;
        virtual ~ClientHandler(){} ;
  
};


#endif //FINAL_PROJECT_SECOND_ClientHandler_H
