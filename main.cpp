#include "graph.hpp"
#include <iostream>
#include <time.h>

int **randomBoard(int width, int height)
{
    int **board;
    srand(time(NULL));
    board = new int *[height + 2];
    for(int y = 0; y < height + 2; y++)
        board[y] = new int[width + 2];
    for(int y = 0; y < height + 2; y++)
    {
        for(int x = 0; x < width + 2; x++)
        {
            if(y == 0 || y == height + 1 || x == 0 || x == width + 1)
                board[y][x] = -1; // Add outer border of the board. Used in
                                  // Graph constructor.
            else
                board[y][x] = 1 + rand() % 9; // Fill with random values
            board[1][1] = 0;                  // Start - weight 0
            board[height][width] = 0;         // End - weight 0
        }
    }
    return board;
}

void printBoard(int **board, int width, int height)
{
    std::cout << "Board (index:weight)" << std::endl;
    int index = 0;
    for(int y = 1; y < height + 1; y++)
    {
        for(int x = 1; x < width + 1; x++)
        {

            board[y][x] == -1
                ? std::cout << "   " // Display fields with weight != -1
                            << "\t"
                : std::cout << index << ":" << board[y][x] << "\t";
            index++;
        }
        std::cout << std::endl;
    }
}
void displayPath(int **board, int width, int height, std::list<int> &path)
{
    int index = 0;
    for(int y = 1; y < height + 1; y++)
    {
        for(int x = 1; x < width + 1; x++)
        {
            bool vertexInPath = false;
            for(auto &v : path)
            {
                if(v == index) // Check if vertex is in path
                {
                    vertexInPath = true;
                    break;
                }
            }
            if(!vertexInPath)
            {
                board[y][x] = -1; // If not in path, change weight to -1
            }
            index++;
        }
    }
    std::cout << "Shortest path displayed on the board" << std::endl;
    printBoard(board, width,
               height); // Print board except fields with weight -1
}

int main()
{
    int width = 6, height = 6;
    int **board = randomBoard(width, height);
    printBoard(board, width, height);

    // Initialize graph
    Graph g(board, width, height);
    // Calculate shortest path
    auto path = g.shortestPath(0, width * height - 1);

    // Print path
    std::cout << std::endl << "Shortest path" << std::endl;
    for(auto &v : path)
        std::cout << "->" << v;
    std::cout << std::endl << std::endl;

    // Display path in the board
    displayPath(board, width, height, path);
}
