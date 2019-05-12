
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include "OpenSocket.h"
#include <iostream>

/* This function receives a port to open the socket to and a flag
 * to set if there was a time out.
 */

int OpenSocket::open_socket(int port) {
  int sock_fd ;
  struct sockaddr_in serv_addr ;
  int enable=1;

  sock_fd = socket(AF_INET, SOCK_STREAM, 0); // calling to socket function

  // Sets the socket to be reused

  if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) != 0){
      perror("Cannot reuse address");
      exit(1);
  }

  if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) != 0){
      perror("Cannot reuse port");
      exit(1);
  }

  if (sock_fd < 0) { // if the function failed, print error
      perror("cannot open socket, please try again");
      exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr)); // initialize the socket struct

  // update socket's data

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);


  if (bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) { // binding host address
      perror("cannot bind to server");
      exit(1);
  }

  return sock_fd ;
}

int OpenSocket::listen_to_client(int sock_fd, int* time_out_flag, bool* is_first_client, int clilen) {
    int new_sock_fd;
    struct sockaddr_in cli_addr ;

    // sets timeout's definition
    timeval client_timeout ;
    client_timeout.tv_sec = 0;
    client_timeout.tv_usec = 0 ;
    timeval server_timeout ;
    if(*is_first_client) {
        server_timeout.tv_sec = std::numeric_limits<int>::max() ;
        *is_first_client = false ;
    }

    else {
        server_timeout.tv_sec = 5;
    }

    server_timeout.tv_usec = 0;
    setsockopt(sock_fd,SOL_SOCKET,SO_RCVTIMEO,(char *)&server_timeout, sizeof(server_timeout));
    setsockopt(new_sock_fd,SOL_SOCKET,SO_RCVTIMEO,(char *)&client_timeout, sizeof(client_timeout));
    // accept the connection request

    new_sock_fd = accept(sock_fd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    if(new_sock_fd < 0)
    {
        if(errno == EWOULDBLOCK)
        {
            std::cout<<"timeout!"<<std::endl;
            *time_out_flag = 1;
        }
        else
        {
            perror("other error");
            exit(3);
        }
    }

//  if (new_sock_fd < 0) { // if connection failed, print error
//      perror("cannot accept your connection request");
//      exit(1);
//  }

    return new_sock_fd ;
}

OpenSocket::~OpenSocket(){};
