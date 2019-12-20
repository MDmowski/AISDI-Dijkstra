#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<queue>
#include<list>

class Graph
{
private: 

    int V;
public:
    Graph(int** board);
    ~Graph();

    void shortestPath(int source , int destination);
}


#endif
