//
// Created by royl8 on 1/9/19.
//

#include "Matrix.h"

/* Constructor for the Matrix class.
 * If the client's input is illegal, set the 'n' (size of matrix) to -1.
 */

Matrix::Matrix(vector<string> matrix_vec) {
    if (!build_matrix(matrix_vec)) {
        this->n = -1 ;
    }
}

/* This function receives a vector of lines and build a matrix
 * using a map with key value of the vertex index and the value is
 * a State which represent this vertex.
 * The last 2 vector's position is the entry and exit vertexes.
 */

bool Matrix::build_matrix(vector<string> matrix_vec) {
    int vec_size = matrix_vec.size() - 2; // variable for the loop to run throw only the lines of the matrix
    vector<string> line_vec;
    this->n = vec_size ;
    for (int i = 0; i < vec_size; i++) { // run throw all lines of the matrix
        // activate a function which parse a line and insert all vertexes into a vector
        line_vec = line_parse(matrix_vec.at(i));
        // activate a function which updates the vertex_map. if the input was illigel, the function
        // returns false.
        if (!update_map(line_vec, i)) { // if input is illegal
            return false ; // return false
        }
    }
    line_vec = line_parse(matrix_vec.at(vec_size)); // parse the entry point line
    entry_vertex = vertex_map[line_vec.at(0) + "," + line_vec.at(1)]; // sets the entry member
    line_vec = line_parse(matrix_vec.at(++vec_size)); // parse the exit point line
    exit_vertex = vertex_map[line_vec.at(0) + "," + line_vec.at(1)]; // sets the exit member
    return true ;
}

/* This function receives a line of a matrix and parse each
 * value into a vector.
 * Each value of the vector represent a vertex's cost.
 */

vector<string> Matrix::line_parse(string line) {
    int start_of_num = 0;
    int end_of_num;
    vector<string> line_vec;
    if (line[line.length() - 1] != ',') {
        line += ",";
    }
    while (true) {
        end_of_num = line.find(',', start_of_num);
        if (end_of_num != -1) {
            line_vec.push_back(line.substr(start_of_num, end_of_num - start_of_num));
            start_of_num = end_of_num + 1;
        } else {
            return line_vec;
        }
    }
}

/* This function receives a vector of vertexes and a line number.
 * The function creates for each vertex a unique index and insert
 * it into the vertex_map.
 */

bool Matrix::update_map(vector<string> line_vec, int i) {
    int vec_length = line_vec.size();
    if(vec_length == this->n) { // if number of vertexes is legal
        State *temp_state;
        string vertex_index;
        for (int j = 0; j < vec_length; j++) { // run throw all vec
            vertex_index = to_string(i) + "," + to_string(j); // creates a index for each vertex
            // initialize a vertex State using the index and the cost
            temp_state = new State(vertex_index, stod(line_vec.at(j)));
            vertex_map.insert(pair<string, State *>(vertex_index, temp_state)); // insert the data into the map
        }
        return true ; // after process is finished successfully, return true
    }
    return false ; // if the input is illegal, return false
}

State *Matrix::getInitialState() {
    return this->entry_vertex;
}

State *Matrix::getGoalState() {
    return this->exit_vertex;
}

unordered_map<string, State*>* Matrix::get_vertex_map() {
    return &this->vertex_map ;
}

int Matrix::get_n() {
    return this->n ;
}

Matrix::~Matrix(){
    unordered_map<string, State *>::iterator it;
    for (it = this->vertex_map.begin(); it != this->vertex_map.end(); ++it) {
        delete(this->vertex_map[it->first]) ;
    }
}