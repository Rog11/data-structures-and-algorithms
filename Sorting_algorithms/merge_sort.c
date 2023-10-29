#define MAX_ARRAY_SIZE 100

// Merge two sorted arrays into a single sorted array
void merge(int array[], int left[], int leftSize, int right[], int rightSize)
{
  int i = 0, j = 0, k = 0;
  // While there are elements in both arrays
  while (i < leftSize && j < rightSize)
  {
    // Compare the current element in each array and append the smaller element to the result array
    if (left[i] < right[j])
    {
      array[k] = left[i];
      i++;
    } 
    else
    {
      array[k] = right[j];
      j++;
    }
    k++;
  }
  // Append the remaining elements of the left array, if any
  while (i < leftSize)
  {
    array[k] = left[i];
    i++;
    k++;
  }
  // Append the remaining elements of the right array, if any
  while (j < rightSize)
  {
    array[k] = right[j];
    j++;
    k++;
  }
}

// Sort an array using the merge sort algorithm
void mergeSort(int array[], int size)
{
  // If the array has more than one element, split it in half
  // and sort each half separately
  if (size > 1) 
  {
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++)
    {
      left[i] = array[i];
    }
    for (int i = 0; i < size - mid; i++)
    {
      right[i] = array[mid + i];
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    // Merge the sorted halves into a single sorted array
    merge(array, left, mid, right, size - mid);
  }
}

int main() 
{
  int array[MAX_ARRAY_SIZE] = {30, 20, 50, 10, 40};
  int size = 5;
  mergeSort(array, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");  // prints 10 20 30 40 50
  return 0;
}
