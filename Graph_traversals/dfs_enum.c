#include <stdio.h>
#include <stdlib.h>

#define N 6

// Enumerated type for node colors
enum color
{
    WHITE,
    GRAY,
    BLACK
};

// Adjacency matrix representation of a graph
int graph[N][N] = {
    {0, 1, 0, 1, 0, 0},
    {1, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 0},
    {0, 0, 1, 1, 0, 1},
    {0, 0, 1, 0, 1, 0}
};

// Array to track the colors of the nodes
enum color colors[N];

// DFS visit function
void dfs_visit(int node)
{
    // Set the color of the current node to gray
    colors[node] = GRAY;
    printf("%d ", node);
    // Visit the neighbors of the current node
    for (int i = 0; i < N; i++)
    {
        if (graph[node][i] && colors[i] == WHITE)
            dfs_visit(i);
    }
    // Set the color of the current node to black
    colors[node] = BLACK;
}

// DFS function
void DFS()
{
    // Initialize all nodes as white
    for (int i = 0; i < N; i++)
        colors[i] = WHITE;

    // Perform DFS on all white nodes
    for (int i = 0; i < N; i++)
    {
        if (colors[i] == WHITE)
            dfs_visit(i);
    }
}

int main()
{
    DFS();

    return 0;
}
