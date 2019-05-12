
#ifndef FINAL_PROJECT_SECOND_CACHMENAGER_H
#define FINAL_PROJECT_SECOND_CACHMENAGER_H

#include <vector>
#include <string>

template <class problem,class solution>
class CacheManager {
    public:
        virtual  bool find_solution(problem) = 0;
        virtual solution get_solution(problem) = 0;
        virtual void write_to_file(std::vector<std::pair<std::string,std::string>> vec) = 0;
        virtual ~CacheManager(){};
};


#endif //FINAL_PROJECT_SECOND_CACHMENAGER_H
