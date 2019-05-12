#include "FileCacheManager.h"
#include <iterator>
#include <pthread.h>
#include "Main.h"

//constructor of FileCacheManger
FileCacheManager::FileCacheManager(std::string name_file)
{
    this->flg = false;
    this->name_file = name_file;
}

/*
 * This function get string problem
 * check if the problem in the map if yes the function return true
 * if not the function check if the map is update if yes return false if not the function update the map and check again
 * if the problem still not in the map return false, if the problem in the map return true
 */
bool FileCacheManager::find_solution(std::string problem)
{
    //check if the problem is in the map
    std::unordered_map<std::string,std::string> :: iterator it;
    it = this->hash_map.find(problem);
    //if yes return true
    if(it != this->hash_map.end())
    {
        return true;
    }
    //if not and the hash_map is update return false
    if(this->flg)
    {
       return false;
    }
    //if the map is not update
    else
    {
        //update the map
        update_map();
        //save that the map is update in this run of the program
        this->flg = true;
        //do this function again and return the right answer now that the map update
        it = this->hash_map.find(problem);
        if(it != this->hash_map.end())
        {
            return true;
        }
        return false;
    }
}

/*
 * This function return solution in o(1)
 * to problems that have already been solved
 */
std::string FileCacheManager:: get_solution(std::string problem)
{
    return this->hash_map[problem] + "\r\n";
}

void FileCacheManager:: add_solution_vec(std::pair<std::string,std::string> solution)
{
    this->vec.push_back(solution);
}

/*
 * This function update the map of the solustion from the file
 */
void FileCacheManager::update_map()
{
    std::ifstream point_file;
    std::string line;
    //if the file do not exists create one
    point_file.open(this->name_file);
    if(point_file)
    {
        //read all the line from the file
        while (getline(point_file, line))
        {
            //inter the data do the map
            line_to_map(line);
        }
        point_file.close();
    }
}
/*
 * This function get a line
 * take the data and inter them to the map in the right way
 */
void FileCacheManager::line_to_map(std::string line)
{
    std::string key;
    std::string value;
    int mark_comma = 0;
    //find mark comma
    mark_comma = line.find('{',0);
    //find the first word
    key = line.substr(0,mark_comma);
    //find the second word
    value = line.substr(mark_comma , line.length() -1);
    //inter the value in to the map
    this->hash_map[key] = value;
}

/*
 * This function get vector
 * in the end of the program write all the vector organs to the file
 */
void FileCacheManager::write_to_file(std::vector<std::pair<std::string,std::string>> vec)
{
    std::string line;
    int len_vec = vec.size();
    this->solution_file.open(this->name_file,std::ios::app);
    //move on all the vector
    for(int i = 0; i < len_vec; i++)
    {
        line = "";
        //save the first word
        std::string one = this->vec.at(i).first;
        //save thr second word
        std::string sec = this->vec.at(i).second;
        //write the solution to the file
        this->solution_file << one<<sec<< "\n";
    }
    this->solution_file.close();
}

/*
 * This function inter new solution to the map
 * after the problem is resolved
 */
void FileCacheManager::add_solution_map(std::string problem,std::string solution)
{
     this->hash_map.insert(std::pair<std::string,std::string>(problem,solution));
}

/*
 * This function free the memory
 * and write the organs in the vector to the file
 */
FileCacheManager::~FileCacheManager()
{
    write_to_file(this->vec);
}