#include <iostream>
#include <limits>
#include <set>
#include <vector>

#include "graph.hpp"

#define INF std::numeric_limits<int>::max()

void Graph::addEdge(int source, int destination, int weight)
{
    adjList[source].push_back(std::make_pair(destination, weight));
}

Graph::~Graph()
{
    delete[] adjList;
}

Graph::Graph(int **board, int width, int height)
{
    V = width * height;
    adjList = new std::list<std::pair<int, int>>[V]; // Creating adjacency list
                                                     // for each vertex

    for(int y = 1; y <= height; y++)
    {
        for(int x = 1; x <= width; x++)
        {
            int index = (y - 1) * width + (x - 1);
            int weight = board[y][x - 1]; // LEFT
            if(weight != -1)              // Checking if not on the border
                addEdge(index, index - 1, weight);

            weight = board[y][x + 1]; // RIGHT
            if(weight != -1)          // Checking if not on the border
                addEdge(index, index + 1, weight);

            weight = board[y - 1][x]; // UP
            if(weight != -1)          // Checking if not on the border
                addEdge(index, index - width, weight);

            weight = board[y + 1][x]; // DOWN
            if(weight != -1)          // Checking if not on the border
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

std::list<int> Graph::shortestPath(int source, int destination)
{
    // dist[v] is distance from source to v
    std::vector<int> dist(V, INF);
    // p[v] is an index of a vertex proceeding v in shortest path from source to
    // v
    std::vector<int> p(V);

    // initialize p with p[v] = v
    int i = 0;
    for(std::vector<int>::iterator it = p.begin(); it != p.end(); ++it)
        *it = i++;

    std::set<std::pair<int, int>> Q; // Set of not processed nodes
    Q.insert(std::make_pair(
        0, source));  // First processed node is source with distance 0
    dist[source] = 0; // Distance from source to source is always 0

    while(!Q.empty())
    {
        // Currently proccesed vertex u
        int u =
            Q.begin()->second; // std::set keeps pairs sorted by first attribute
        Q.erase(Q.begin());    // remove u from Q

        // For each vertex v in neighbours of u
        for(std::list<std::pair<int, int>>::iterator it = adjList[u].begin();
            it != adjList[u].end(); ++it)
        {
            // Current vertex v and the weight of edge (u, v)
            int v = it->first;
            int w = it->second;

            // Better path found?
            if(dist[v] > dist[u] + w)
            {
                // Update vertex v in Q with new dist
                if(dist[v] != INF)
                    Q.erase(Q.find(std::make_pair(dist[v], v)));

                dist[v] = dist[u] + w;
                // Save new predecessor
                p[v] = u;
                Q.insert(std::make_pair(dist[v], v));
            }
        }
    }

    std::list<int> path;
    // If shortest path exists, construct it
    if(dist[destination] != INF)
    {
        path.push_front(destination);
        int v = destination;
        // Traverse through predecessor list until source is reached
        do
        {
            v = p[v];
            path.push_front(v);
        } while(v != source);
    }
    else
        path.push_front(source); // Path only consists of source

    return path;
}
