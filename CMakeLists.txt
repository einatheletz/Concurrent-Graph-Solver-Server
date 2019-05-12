cmake_minimum_required(VERSION 3.13)
project(final_project_second)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(final_project_second main.cpp MySerialServer.cpp MySerialServer.h Server.h OpenThread.cpp
        OpenThread.h MyParallelServer.cpp MyParallelServer.h ClientHandler.h MyTestClient.cpp MyTestClient.h
        OpenSocket.cpp OpenSocket.h Solver.h CacheManager.h BestFS.cpp BestFS.h FileCacheManager.cpp FileCacheManager.h StringReverse.cpp
        StringReverse.h MyClientHandler.cpp MyClientHandler.h Matrix.cpp Matrix.h State.h State.cpp BFS.cpp BFS.h Searcher.h Searchable.h AStar.cpp AStar.h SearchableUtility.cpp SearchableUtility.h DFS.cpp DFS.h GraphSolver.cpp GraphSolver.h)
