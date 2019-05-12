#ifndef FINAL_PROJECT_SECOND_MYPARALLELSERVER_H
#define FINAL_PROJECT_SECOND_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer : public server_side::Server {

private:
    OpenThread *openThread;
    ClientHandler* client_handler ;
    vector<pthread_t> threads_id ;

    public:
        MyParallelServer() ;
        void open(int port, ClientHandler* client_handler);
        virtual ~MyParallelServer() ;
};

struct solver_struct {
    int port ;
    ClientHandler* c_h ;

};


#endif //FINAL_PROJECT_SECOND_MYPARALLELSERVER_H
