#include "graph.hpp"
#include <iostream>

void Graph::addEdge(int source, int destination, int weight)
{
    adjList[source].push_back(std::make_pair(destination, weight));
}

Graph::Graph(int **board, int width, int height)
{
    V = width * height;
    adjList = new std::list<std::pair<int, int>>[V];

    for(int y = 1; y <= height; y++)
    {
        for(int x = 1; x <= width; x++)
        {
            int index = (y - 1) * width + (x - 1);
            int weight = board[y][x - 1]; // LEFT
            if(weight != -1)
                addEdge(index, index - 1, weight);

            weight = board[y][x + 1]; // RIGHT
            if(weight != -1)
                addEdge(index, index + 1, weight);

            weight = board[y - 1][x]; // UP
            if(weight != -1)
                addEdge(index, index - width, weight);

            weight = board[y + 1][x]; // DOWN
            if(weight != -1)
                addEdge(index, index + width, weight);
        }
    }
}

void Graph::print()
{
    for(int i = 0; i < V; i++)
    {
        std::cout << "Vertex " << i << " edges:" << std::endl;
        for(auto const &edge : adjList[i])
        {
            std::cout << "\tDestination: " << edge.first
                      << " Weight: " << edge.second << std::endl;
        }
    }
}