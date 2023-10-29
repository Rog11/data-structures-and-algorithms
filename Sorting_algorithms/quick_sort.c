#define MAX_ARRAY_SIZE 100

// Partition an array around a pivot element
int partition(int array[], int low, int high)
{
  // Choose the pivot element as the last element in the array
  int pivot = array[high];
  // Keep track of the index of the smaller element
  int i = low - 1;
  // Iterate through the array
  for (int j = low; j <= high - 1; j++)
  {
    // If the current element is smaller than or equal to the pivot, swap it with the element at index i + 1
    if (array[j] <= pivot)
    {
      i++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  // Swap the pivot element with the element at index i + 1
  int temp = array[i + 1];
  array[i + 1] = array[high];
  array[high] = temp;
  // Return the index of the pivot element
  return i + 1;
}

// Sort an array using the quicksort algorithm
void quickSort(int array[], int low, int high)
{
  // If the array has more than one element, partition it
  // and sort each partition separately
  if (low < high)
  {
    int pivotIndex = partition(array, low, high);
    quickSort(array, low, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, high);
  }
}

int main()
{
  int array[MAX_ARRAY_SIZE] = {30, 20, 50, 10, 40};
  int size = 5;
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");  // prints 10 20 30 40 50
  return 0;
}
