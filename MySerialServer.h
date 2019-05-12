
#ifndef FINAL_PROJECT_SECOND_MYSRIALSERVER_H
#define FINAL_PROJECT_SECOND_MYSRIALSERVER_H

#include "Server.h"

// class that solve clients problems in a differenet thread in serial

class MySerialServer : public server_side::Server {
    private:
        OpenThread *openThread;
        ClientHandler* client_handler ;

    public:
        MySerialServer();
        virtual void open(int port, ClientHandler* client_handler);
        virtual ~MySerialServer();
};


#endif //FINAL_PROJECT_SECOND_MYSRIALSERVER_H
