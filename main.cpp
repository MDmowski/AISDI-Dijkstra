#include "graph.hpp"
#include <iostream>
#include <time.h>

int **randomBoard(int width, int height)
{
    int **board;
    srand(time(NULL));
    board = new int *[height + 2];
    for(int i = 0; i < height + 2; i++)
        board[i] = new int[width + 2];
    for(int i = 0; i < height + 2; i++)
    {
        for(int j = 0; j < width + 2; j++)
        {
            if(i == 0 || i == height + 1 || j == 0 || j == width + 1)
                board[i][j] = -1;
            else
                board[i][j] = 1 + rand() % 9;
            board[1][1] = 0;
            board[height][width] = 0;
        }
    }
    return board;
}

void printBoard(int **board, int width, int height)
{
    std::cout << "Board (index:weight)" << std::endl;
    int index = 0;
    for(int i = 1; i < height + 1; i++)
    {
        for(int j = 1; j < width + 1; j++)
        {
            std::cout << index << ":" << board[i][j] << "\t";
            index++;
        }
        std::cout << std::endl;
    }
}

int main()
{
    int width = 6, height = 6;
    int **board = randomBoard(width, height);
    printBoard(board, width, height);

    // Initialize graph
    Graph g(board, width, height);
    // Calculate shortest path
    auto path = g.shortestPath(0, 35);

    // Print path
    std::cout << std::endl;
    for(auto &v: path)
        std::cout << "->" << v;
    std::cout << std::endl;
}
