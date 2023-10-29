#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Adjacency matrix representation of a graph
int** adjMatrix;

int main() 
{
  // Open the file
  FILE* fp = fopen("graph.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file\n");
    return 1;
  }
 
  // Read the number of vertices and edges from the file
  int numVertices, numEdges;
  fscanf(fp, "%d %d", &numVertices, &numEdges);
 
  // Allocate memory for the adjacency matrix
  adjMatrix = (int**)malloc(numVertices * sizeof(int*));
  for (int i = 0; i < numVertices; i++)
  {
    adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
  }
 
  // Initialize the adjacency matrix
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      adjMatrix[i][j] = 0;
    }
  }
 
  // Read the edges from the file and add them to the adjacency matrix
  for (int i = 0; i < numEdges; i++)
  {
    int from, to, weight;
    fscanf(fp, "%d %d %d", &from, &to, &weight);
    adjMatrix[from][to] = weight;
  }
 
  // Close the file
  fclose(fp);
 
  // The adjacency matrix is now populated with the data from the file
  return 0;
}
