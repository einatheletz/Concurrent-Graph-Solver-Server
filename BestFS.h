//
// Created by einat on 1/12/19.
//

#ifndef FINAL_PROJECT_SECOND_BESTFS_H
#define FINAL_PROJECT_SECOND_BESTFS_H

#include "Searcher.h"
#include <vector>
#include "State.h"
#include "SearchableUtility.h"

class BestFS : public Searcher {
    private:
        int evaluated_nodes;
        static vector<pair<double ,State*>>::iterator find_lowest_cost(vector<pair<double ,State*>>* vec) ;
        static map<string, double> build_f_map(unordered_map<string, State *> *vertex_map);
       // bool find_in_vec(vector<State*> vec,State );
    public:
        virtual string search(Searchable* searchable);
        virtual ~BestFS();
        // string searchtwo(Searchable* searchable);
        virtual int getNumberOfNodesEvaluated();
};


#endif //FINAL_PROJECT_SECOND_BESTFS_H
