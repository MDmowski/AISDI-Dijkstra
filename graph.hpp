#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <queue>

class Graph
{
  private:
    int V;
    std::list< std::pair<int, int> > *adjList;

  public:
    Graph(int** board, int width, int height);
    ~Graph(){};
    void addEdge(int source, int destination, int weight);
    void print();

    void shortestPath(int source, int destination);
};

#endif
