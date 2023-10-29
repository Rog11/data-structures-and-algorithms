#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumerated type for colors
enum color { WHITE, GRAY, BLACK };

// Structure for a node in the linked list
typedef struct node
{
    int value;
    enum color color;
    struct node *next;
} Node;

// Structure for the linked list
typedef struct list
{
    Node *head;
} List;

// Depth-first search function
void DFS(List *graph, int N)
{
    // Initialize the colors of all the nodes to white
    for (int i = 0; i < N; i++)
    {
        Node *node = graph[i].head;
        while (node != NULL)
        {
            node->color = WHITE;
            node = node->next;
        }
    }

    // Call dfs_visit on all white nodes
    for (int i = 0; i < N; i++)
    {
        if (graph[i].head->color == WHITE)
            dfs_visit(graph[i].head);
    }
}

// Depth-first search visit function
void dfs_visit(Node *node)
{
    // Set the color of the current node to gray
    node->color = GRAY;
    printf("%d ", node->value);
    // Visit the neighbors of the current node
    Node *neighbor = node->next;
    while (neighbor != NULL)
    {
        if (neighbor->color == WHITE)
        {
            dfs_visit(neighbor);
        }
        neighbor = neighbor->next;
    }
    // Set the color of the current node to black
    node->color = BLACK;
}

int main()
{
    // Open the input file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Read the number of nodes from the first line of the file
    int N;
    fscanf(fp, "%d", &N);

    // Create an array of linked lists to represent the graph
    List graph[N];
    // Initialize each linked list
    for (int i = 0; i < N; i++)
    {
        graph[i].head = NULL;
    }

    // Read the edges from the file and add them to the linked lists
    int node1, node2;
    while (fscanf(fp, "%d,%d", &node1, &node2) == 2)
    {
        // Add node2 to the linked list for node1
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->value = node2;
        newNode->color = WHITE;
        newNode->next = graph[node1].head;
        graph[node1].head = newNode;
    }

    // Close the input file
    fclose(fp);

    // Perform a depth-first search on the graph
    DFS(graph, N);

    return 0;
}