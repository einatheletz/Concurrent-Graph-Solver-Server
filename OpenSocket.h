
#ifndef FINAL_PROJECT_SECOND_OPENSOCKET_H
#define FINAL_PROJECT_SECOND_OPENSOCKET_H

#include <limits>
#include <iostream>

/* This class open a socket using a given port.
 * If there was a timeout during the wait for a client,
 * the class changes the time out flag
 */

class OpenSocket {

    public:
        int open_socket(int port) ;
        int listen_to_client(int sock_fd, int* time_out_flag, bool* is_first_client, int clilen) ;
        ~OpenSocket();

};


#endif //FINAL_PROJECT_SECOND_OPENSOCKET_H
