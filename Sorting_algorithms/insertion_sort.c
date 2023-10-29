#define MAX_ARRAY_SIZE 100

void insertionSort(int array[], int size)
{
  // Iterate through the array, starting from the second element
  for (int i = 1; i < size; i++) 
  {
    // Save the value of the current element
    int value = array[i];
    // Save the index of the current element
    int j = i;
    // Shift all elements that are greater than the current element
    // to the right, until we find the correct position for the current element
    while (j > 0 && array[j - 1] > value)
    {
      array[j] = array[j - 1];
      j--;
    }
    // Insert the current element in its correct position
    array[j] = value;
  }
}

int main()
{
  int array[MAX_ARRAY_SIZE] = {30, 20, 50, 10, 40};
  int size = 5;
  insertionSort(array, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");  // prints 10 20 30 40 50
  return 0;
}