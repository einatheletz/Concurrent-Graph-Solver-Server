
#ifndef FINAL_PROJECT_SECOND_MYTESTCLIENT_H
#define FINAL_PROJECT_SECOND_MYTESTCLIENT_H

#include <string>
#include <iostream>
#include "ClientHandler.h"

using namespace std ;

class MyTestClient: public ClientHandler {

  private:
        Solver<string, string>* solver ;
  
  public:
        MyTestClient(Solver<string, string>* string_solver) ;
        void handle_client(int sock_fd) ;
        bool is_end_line(char buffer[]) ;
        virtual ~MyTestClient();

};


#endif //FINAL_PROJECT_SECOND_MYTESTCLIENT_H
