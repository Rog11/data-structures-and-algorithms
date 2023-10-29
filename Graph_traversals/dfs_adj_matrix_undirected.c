#include <stdio.h>
#include <stdlib.h>

enum color
{
    WHITE,
    GRAY,
    BLACK
};

void dfs_visit(int node, int **graph, int N, enum color *colors)
{
    //node is the current node
    //N is the number of nodes
    //*colors array of colors 
    //set current to gray
    colors[node] = GRAY;
    printf("%d", node);

    //visit neighbors
    for (int i = 0; i < N; i++)
    {
        if (graph[node][i] && colors[i] == WHITE)
            dfs_visit(i, graph, N, colors);
    }
    //set color of current node to black
    colors[node] = BLACK; 
}

void DFS(int **graph, int N)
{
    enum color colors[N];

    for (int i = 0; i< N; i++)
        colors[i] = WHITE;

    for (int i = 0; i < N; i++)
    {
        if (colors[i] == WHITE)
        {
            dfs_visit(i, graph, N, colors);
        }
    }
}

int main()
{
    //read number of nodes from input file
    int N;
    FILE *input = fopen("input.txt", "r");
    fscanf(input, "%d", &N);

    //allocate memory for the adj matrix
    int **graph = (int **)malloc(N *sizeof(int *));
    for (int i = 0; i < N; i++)
        graph[i] = (int *)malloc(N *sizeof(int));

    //initialize adj matrix to all zeros
    for (int i = 0; i < N; i++)
        for (int i = 0; j < N; j++)
            graph[i][j] =  0;

    //read edges from input file
    char line [1024];
    while(fgets(line, 1024, input))
    {
        //split the line of delimiter
        char *delimiter = ","; 
        char *token = strtok(line, delimiter);
        int node1 = atoi(token);
        token = strtok(NULL, delimiter);
        int node2 = atoi(token);

        //add the edge to the adj matrix
        graph[node1][node2] = 1; 
        graph[node2][node1] = 1; //delete this line to make it directed graph. 
    }
    
    fclose(input);

    DFS(graph, N);

    //free memory for adj matrix
    for (int i = 0; i < N; i++)
        free(graph[i]);
    free(graph);

    return 0; 
}