# Solver-Server

My implementation of a server which recive a Matrix and it's "costs" of each vertex / edges, entry position and goal position and calculate the shortest path between them.

The server can help one client at a time in serial or mulitple clients in parrellel in different threads.

The algorithems are implemented to calculate the path are: AStar, BFS, DFS and Breadth First Search.

After an experiment on 10 Matrixes in diffrenet sizes, the most effective algorithem was AStar which I chose to be the default algorithem.
