#include <stdio.h> 
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int dest; 
    struct Node *next; 
} Node;

typedef struct Graph {
    int num_nodes; 
    Node *adj_list[MAX_NODES];
} Graph; 

void add_edge(Graph *g, int src, int dest)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->dest = dest;
    new_node->next = NULL;

    if (g->adj_list[src] == NULL)
    {
        g->adj_list[src] = new_node;
    }
    else
    {
        new_node->next = g->adj_list[src];
        g->adj_list[src] = new_node;
    }
}

void dfs(Graph *g, int node, int visited[])
{
    visited[node] = 1; 
    printf("%d", node);

    Node *curr = g->adj_list[node];
    while(curr != NULL)
    {
        int adj_node = curr->dest;
        if (!visited[adj_node])
        {
            dfs(g, adj_node, visited);
        }
        curr = curr->next;
    }
}

int main()
{
    Graph g; 
    g.num_nodes = 5;
    for (int i = 0; i < g.num_nodes; i++)
    {
        g.adj_list[i] = NULL;
    }
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 2, 0);
    add_edge(&g, 3, 3);

    int visited[MAX_NODES] = {0};
    dfs(&g, 2, visited);

    return 0; 
}
