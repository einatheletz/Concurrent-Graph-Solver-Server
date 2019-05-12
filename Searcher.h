//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_SEARCHER_H
#define FINAL_PROJECT_SECOND_SEARCHER_H

#include <string>
#include <queue>
#include <unordered_map>
#include <limits>
#include "Searchable.h"
#include "SearchableUtility.h"

using namespace std ;

class Searcher {

    public:
        virtual string search(Searchable* searchable) = 0;
        virtual ~Searcher(){};
        virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //FINAL_PROJECT_SECOND_SEARCHER_H
