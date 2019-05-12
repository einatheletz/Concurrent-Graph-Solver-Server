
#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(Solver<vector<string>, string> *searcher_solver) {
    this->searcher_solver = searcher_solver;
}

/* This function will be activate from an other thread than the "main thread".
 * The function receives a socket id to communicate to.
 * The function reads the client inputs until it receives "end". than the function
 * activates the solver for finding the shortest path between two points.
 */

void MyClientHandler::handle_client(int sock_fd) {
    char buffer[256];
    char *answer;
    string line = "";
    string temp_buffer;
    vector<string> matrix_vec;
    while (true) {
        memset(buffer, 0, 256) ; // zeros the buffer
        int n = read(sock_fd, buffer, 256); // reads client's input
        if (n < 0) { // if read is fail, print error
            perror("ERROR reading from socket");
        }
        temp_buffer = buffer ;
        if (!is_end_line(&temp_buffer)) { // checks if the input is a whole line
            line += temp_buffer ; // if it is not, it keeps the sub line
            continue ;
        }
        line += temp_buffer;
        if (line != "end") { // if line is not "end"
            matrix_vec.push_back(line); // push it into the matrix vector
            line = "" ;
        }
        else {
            Searchable* temp_matrix = new Matrix(matrix_vec) ; // calling the Matrix constructor that initialize a matrix
            temp_buffer = this->searcher_solver->solve(matrix_vec) ;
            answer = &temp_buffer[0] ;
            n = write(sock_fd, answer, temp_buffer.length()); // write the solution to client
            delete(temp_matrix) ;
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            break;
        }
    }
}

/* This function checks if the buffer received is a complete line.
 * If it is a complete line, return true. else, false.
 */

bool MyClientHandler::is_end_line(string* buffer) {
    int is_end = buffer->find("\r", 0); // find if there is an end line sign
    if (is_end == -1) { // if there is not, return false
        return false;
    }
    else {
        buffer->erase(is_end, 2) ; // if it is, delete the sign and return true
        return true;
    }

}

// destructor

MyClientHandler::~MyClientHandler()
{
    delete(this->searcher_solver);
}