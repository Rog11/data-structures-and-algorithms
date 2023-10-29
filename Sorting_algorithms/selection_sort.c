#define MAX_ARRAY_SIZE 100

void selectionSort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }
    int temp = array[i];
    array[i] = array[minIndex];
    array[minIndex] = temp;
  }
}

int main() {
  int array[MAX_ARRAY_SIZE] = {30, 20, 50, 10, 40};
  int size = 5;
  selectionSort(array, size);
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");  // prints 10 20 30 40 50
  return 0;
}
