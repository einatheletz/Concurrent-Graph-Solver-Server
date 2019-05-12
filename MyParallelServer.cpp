
#include "MyParallelServer.h"
#include "Main.h"

MyParallelServer::MyParallelServer()
{
    this->openThread = new OpenThread();
}

void MyParallelServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ;
    pthread_t thread_id = this->openThread->open_thread(port, this->client_handler, 1);
    pthread_join(thread_id, nullptr) ;
}

MyParallelServer::~MyParallelServer(){
    delete (this->openThread);
};
