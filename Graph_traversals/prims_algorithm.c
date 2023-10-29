#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HEAP_SIZE 100

// Struct for a heap node
struct HeapNode {
  int element;  // Element stored in the node
  int priority; // Priority of the element
};

// Struct for a min heap
struct MinHeap {
  int size;      // Number of heap nodes present currently
  int capacity;  // Capacity of min heap
  int* pos;      // This is needed for decreaseKey()
  struct HeapNode** array;
};

// Function to create a new min heap node
struct HeapNode* newHeapNode(int element, int priority)
{
  struct HeapNode* heapNode = (struct HeapNode*) malloc(sizeof(struct HeapNode));
  heapNode->element = element;
  heapNode->priority = priority;
  return heapNode;
}

// Function to create a min heap
struct MinHeap* createMinHeap(int capacity)
{
  struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
  minHeap->pos = (int*) malloc(capacity * sizeof(int));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct HeapNode**) malloc(capacity * sizeof(struct HeapNode*));
  return minHeap;
}

// Function to swap two heap nodes
void swapHeapNodes(struct HeapNode** a, struct HeapNode** b)
{
  struct HeapNode* temp = *a;
  *a = *b;
  *b = temp;
}

// Function to heapify a min heap
void minHeapify(struct MinHeap* minHeap, int idx)
{
  int smallest, left, right;
  smallest = idx;
  left = 2 * idx + 1;
  right = 2 * idx + 2;
 
  if (left < minHeap->size && minHeap->array[left]->priority < minHeap->array[smallest]->priority)
  {
    smallest = left;
  }
 
  if (right < minHeap->size && minHeap->array[right]->priority < minHeap->array[smallest]->priority)
  {
    smallest = right;
  }
 
  if (smallest != idx)
  {
    // The nodes to be swapped in min heap
    struct HeapNode *smallestNode = minHeap->array[smallest];
    struct HeapNode *idxNode = minHeap->array[idx];
 
    // Swap positions
    minHeap->pos[smallestNode->element] = idx;
    minHeap->pos[idxNode->element] = smallest;

    // Swap the nodes
    swapHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
    
    // Heapify the min heap
    minHeapify(minHeap, smallest);
}

// Function to check if the min heap is empty
int isEmpty(struct MinHeap* minHeap)
{
  return minHeap->size == 0;
}

// Function to extract the minimum element from the min heap
struct HeapNode* extractMin(struct MinHeap* minHeap)
{
  if (isEmpty(minHeap))
  {
    return NULL;
  }
 
  // Store the root node
  struct HeapNode* root = minHeap->array[0];
 
  // Replace the root node with the last node
  struct HeapNode* lastNode = minHeap->array[minHeap->size - 1];
  minHeap->array[0] = lastNode;
 
  // Update the position of the last node
  minHeap->pos[root->element] = minHeap->size - 1;
  minHeap->pos[lastNode->element] = 0;
 
  // Decrease the size of the heap
  --minHeap->size;
  minHeapify(minHeap, 0);
 
  return root;
}

// Function to decrease the priority of a given vertex
void decreaseKey(struct MinHeap* minHeap, int element, int newPriority)
{
  // Get the index of the vertex in the heap
  int i = minHeap->pos[element];
 
  // Update the priority of the vertex
  minHeap->array[i]->priority = newPriority;
 
  // Heapify the min heap
  while (i && minHeap->array[i]->priority < minHeap->array[(i - 1) / 2]->priority)
  {
    // Swap the vertex with its parent
    minHeap->pos[minHeap->array[i]->element] = (i - 1) / 2;
    minHeap->pos[minHeap->array[(i - 1) / 2]->element] = i;
    swapHeapNodes(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
 
    // Update the index
    i = (i - 1) / 2;
  }
}

// Function to check if a given vertex is in the min heap
bool isInMinHeap(struct MinHeap* minHeap, int element)
{
  if (minHeap->pos[element] < minHeap->size)
  {
    return true;
  }
  return false;
}

int main()
{
  // Create a min heap with capacity 10
  struct MinHeap* minHeap = createMinHeap(10);
 
  // Insert some elements into the min heap
  insert(minHeap, 0, 0);
  insert(minHeap, 1, 1);
  insert(minHeap, 2, 2);
  insert(minHeap, 3, 3);
  insert(minHeap, 4, 4);
  insert(minHeap, 5, 5);
  insert(minHeap, 6, 6);
  insert(minHeap, 7, 7);
  insert(minHeap, 8, 8);
  insert(minHeap, 9, 9);
 
  // Print the elements in the min heap
  printf("Elements in the min heap:\n");
  while (!isEmpty(minHeap))
  {
    struct HeapNode* node = extractMin(minHeap);
    printf("%d ", node->element);
  }
 
  return 0;
}
