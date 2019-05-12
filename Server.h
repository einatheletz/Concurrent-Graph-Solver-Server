
#ifndef FINAL_PROJECT_SECOND_SERVER_H
#define FINAL_PROJECT_SECOND_SERVER_H

#include <pthread.h>
#include "ClientHandler.h"
#include "OpenThread.h"

namespace server_side {

    class Server {

        public:
            virtual void open(int port, ClientHandler* client_handler) = 0;
            virtual ~Server(){} ;
    };
}

#endif //FINAL_PROJECT_SECOND_SERVER_H
