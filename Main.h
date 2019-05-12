
#ifndef FINAL_PROJECT_SECOND_MAIN_H
#define FINAL_PROJECT_SECOND_MAIN_H
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClient.h"
#include "ClientHandler.h"
#include "StringReverse.h"
#include "Matrix.h"
#include "MyParallelServer.h"
#include "Searcher.h"
#include "BFS.h"
#include "AStar.h"
#include "DFS.h"
#include "BestFS.h"
#include <iterator>
#include <random>

#include "MyClientHandler.h"
#include "GraphSolver.h"

static pthread_mutex_t mutex1 ;
static pthread_mutex_t mutex2 ;
static pthread_mutex_t mutex3 ;

namespace boot {

    class Main {
    public:
        void main(int port) {
            Solver<vector<string>, string> *solver = new GraphSolver();
            server_side::Server *A = new MyParallelServer;
            ClientHandler *B = new MyClientHandler(solver);
            A->open(port, B);
            delete(A);
            delete(B);

        }
    };

}

#endif //FINAL_PROJECT_SECOND_MAIN_H
