#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>

class Graph
{
  private:
    int V;                                   // Number of vertices
    std::list<std::pair<int, int>> *adjList; // Adjacency list of each vertex

  public:
    Graph(int **board, int width,
          int height); // Initialize grapth with board pointer
    ~Graph(){};
    void addEdge(int source, int destination,
                 int weight); // Add edge (destination, weight)
    void print();             // Display graph

    std::list<int> shortestPath(int source, int destination);
};

#endif
