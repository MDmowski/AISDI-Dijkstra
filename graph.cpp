#include<vector>
#include<limits>

#include "graph.hpp"



void Graph::shortestPath(int source, int destination)
{
    std::set<pair<int, int>> visited;
    std::vector<int> dist(V, std::numeric_limits<int>::infinity());
    std::vector<int> path;

    visited.insert(make_pair(0, source));
    dist[source] = 0;

    while(!visited.empty())
    {
        // Currently processed vertex
        int u = visited.begin()->second;
        visited.erase(visited.begin());

        list<pair<int, int>>::iterator neighbour;
        for(neighbour = adjList[u].begin(), neighbour != adjList[u].end(), neighbour++)
        {
            int v = neighbour->first;
            int weight = neighbour->second;

        }

    }
}
