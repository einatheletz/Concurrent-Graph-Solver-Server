# Concurrent-Graph-Solver-Server
## Description
Server application for simultaneously solving distance problems, learning multi-threading, sockets and Cache Management, implementing distance algorithms:
* BFS
* DFS
* A-Star
* Best First Search.

## Cache Manager
Before solving the first task in the queue, the program will load its previous calculated jobs from a file. The results will be flushed to the cache only when the program exits. Access to an item from the cache is as fast as O(1) since I used a hash table.

## Concurrency
According to the requirements of my lecturers, I implemented concurrency in a naive way instead of using thread pool.