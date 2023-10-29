#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Structure to represent an edge in the graph
struct Edge {
  int from, to, weight;
};

// Comparison function to use in the sort function
int compare(struct Edge a, struct Edge b)
{
  return a.weight < b.weight;
}

// Disjoint-set data structure to keep track of the connected components
int parent[MAX_VERTICES];

// Function to find the root of a node
int find(int x)
{
  if (parent[x] == x)
  {
    return x;
  }
  return parent[x] = find(parent[x]);
}

// Function to perform Kruskal's algorithm
void kruskal(struct Edge* edges, int numEdges, int numVertices)
{
  // Sort the edges in non-decreasing order of their weights
  sort(edges, edges + numEdges, compare);
 
  // Initialize the disjoint-set data structure
  for (int i = 0; i < numVertices; i++)
  {
    parent[i] = i;
  }
 
  // Initialize the minimum spanning tree
  struct Edge mst[numVertices - 1];
  int mstIndex = 0;
 
    // Perform Kruskal's algorithm
  for (int i = 0; i < numEdges; i++)
  {
    // Find the roots of the two vertices of the current edge
    int fromRoot = find(edges[i].from);
    int toRoot = find(edges[i].to);
 
    // If the two vertices are not in the same connected component, add the edge to the MST
    if (fromRoot != toRoot)
    {
      mst[mstIndex++] = edges[i];
      parent[fromRoot] = toRoot;
    }
  }
 
  // Print the MST
  printf("Minimum spanning tree:\n");
  for (int i = 0; i < numVertices - 1; i++)
  {
    printf("%d -> %d (%d)\n", mst[i].from, mst[i].to, mst[i].weight);
  }
}

int main() 
{
  // Read the number of vertices and edges from the user
  int numVertices, numEdges;
  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &numVertices, &numEdges);
 
  // Read the edges from the user
  struct Edge edges[MAX_EDGES];
  for (int i = 0; i < numEdges; i++)
  {
    printf("Enter edge %d (from, to, weight): ", i + 1);
    scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);
  }
 
  // Perform Kruskal's algorithm
  kruskal(edges, numEdges, numVertices);
 
  return 0;
}

