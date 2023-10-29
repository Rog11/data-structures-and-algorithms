#define MAX_ARRAY_SIZE 100

void bubbleSort(int array[], int size) 
{
  // Iterate through the array, starting from the first element
  for (int i = 0; i < size - 1; i++)
  {
    // Iterate through the array, starting from the first element that has not been sorted yet
    for (int j = 0; j < size - i - 1; j++)
    {
      // If the current element is greater than the next element, swap them
      if (array[j] > array[j + 1])
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() 
{
  int array[MAX_ARRAY_SIZE] = {30, 20, 50, 10, 40};
  int size = 5;
  bubbleSort(array, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");  // prints 10 20 30 40 50
  return 0;
}
