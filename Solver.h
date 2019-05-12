

#ifndef FINAL_PROJECT_SECOND_SOLVER_H
#define FINAL_PROJECT_SECOND_SOLVER_H

template <class problem,class solution>
class Solver {

public:
    virtual solution solve(problem) = 0;
    virtual ~Solver(){};
};


#endif //FINAL_PROJECT_SECOND_SOLVER_H
