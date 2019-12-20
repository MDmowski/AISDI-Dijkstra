#ifndef GRAPH_HPP
#define GRAPH_HPP

#include<list>
#include<utility>

class Graph
{
private: 
    std::list<pair<int, int>> *adjList;
    int V;
public:
    Graph(int** board);
    ~Graph();

    void shortestPath(int source , int destination);
}


#endif
