//
// Created by royl8 on 1/9/19.
//

#ifndef FINAL_PROJECT_SECOND_STATE_H
#define FINAL_PROJECT_SECOND_STATE_H

#include <string>
#include <iostream>
#include <math.h>
#include <string>

using namespace std ;

// These class represent a vertex

class State {

    State* father ; // it's father (came from)
    string vertex_index ; // it's index with syntax of "i,j"
    double cost ; // it's cost

public:
    State(string vertex_index, double cost) ;
    State* get_father() ;
    string get_vertex_index() ;
    double get_cost() ;
    void set_father (State* father) ;
    void set_vertex(string vertex) ;
    void set_cost(double cost) ;
    int get_i() ;
    int get_j();
    double calc_heuristic(State* goal) ; // function which calculate the vertex's heuristic to the
                                         // to the goal vertex
    ~State();
};


#endif //FINAL_PROJECT_SECOND_STATE_H
