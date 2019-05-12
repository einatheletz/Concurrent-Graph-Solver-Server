
#include "MySerialServer.h"

MySerialServer::MySerialServer()
{
    this->openThread = new OpenThread(); // initialize an Open Thread member
}

void MySerialServer::open(int port, ClientHandler* client_handler)
{
    this->client_handler = client_handler ; // set the c_h to a member
    // open a new thread to communicate with clients in serial
    pthread_t thread_id =  this->openThread->open_thread(port, this->client_handler, 0);
    pthread_join(thread_id, NULL) ; // main thread will wait until the communication is finish
}

MySerialServer::~MySerialServer()
{
    delete(this->openThread);
}