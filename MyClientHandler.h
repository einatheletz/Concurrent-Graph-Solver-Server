//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H
#define FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H


#include <string>
#include <iostream>
#include <vector>
#include "ClientHandler.h"
#include "Matrix.h"

using namespace std ;

/* This class is for handling server-client communication when the
 * input will be a Matrix.
 */

class MyClientHandler: public ClientHandler {

private:
    Solver<vector<string>, string>* searcher_solver ;
    bool is_end_line(string* buffer) ;
    virtual ~MyClientHandler() ;

public:
    MyClientHandler(Solver<vector<string>, string>* string_solver) ;
    virtual void handle_client(int sock_fd) ;

};


#endif //FINAL_PROJECT_SECOND_MYCLIENTHANDLER_H
