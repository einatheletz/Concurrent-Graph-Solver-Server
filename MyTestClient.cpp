
#include "MyTestClient.h"

MyTestClient::MyTestClient(Solver<string, string>* string_solver) {
  this->solver = string_solver ;
}

void MyTestClient::handle_client(int sock_fd) {
  char buffer [256] ;
  char* answer ;
  string problem = "" ;
  string temp_buffer ;
  while (true) {
    memset(buffer, 0, 256) ;
    int n = read(sock_fd, buffer, 255) ;
    temp_buffer = buffer ;
    if (!is_end_line(buffer)) {
      problem += temp_buffer ;
      continue ;
    }
    problem += temp_buffer ;
    if (n < 0) { // if read is fail, print error
        perror("ERROR reading from socket");
    }
    else {
      if (problem != "end\r\n") {
        temp_buffer = this->solver->solve(problem);
        answer = &temp_buffer[0] ;
        n = write(sock_fd, answer, temp_buffer.length());
        problem = "" ;
        if (n < 0) {
          perror("ERROR writing to socket");
          exit(1);
        }
      }
      else {
        break ;
      }  
    }
  }
}

bool MyTestClient::is_end_line(char buffer[]) {
  string temp_buffer = buffer ;
  int is_end = temp_buffer.find('\r\n', 0) ;
  if (is_end == -1) {
    return false ;
  }
  return true ;
}

MyTestClient::~MyTestClient(){};
