
#ifndef FINAL_PROJECT_SECOND_FILECACHMENGER_H
#define FINAL_PROJECT_SECOND_FILECACHMENGER_H

#include "CacheManager.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>


class FileCacheManager : public CacheManager<std::string,std::string> {
    private:
        std::unordered_map<std::string,std::string> hash_map;
        bool flg;
        std::vector<std::pair<std::string,std::string>> vec;
        std::fstream solution_file;
        std::string name_file;
        void line_to_map(std::string line);
        void update_map();

    public:
        FileCacheManager(std::string name_file);
        virtual bool find_solution(std::string problem);
        virtual std::string get_solution(std::string problem);
        void add_solution_vec(std::pair<std::string,std::string> solution);
        void add_solution_map(std::string problem,std::string solution);
        virtual void write_to_file(std::vector<std::pair<std::string,std::string>> vec);
        virtual ~FileCacheManager();
};


#endif //FINAL_PROJECT_SECOND_FILECACHMENGER_H
