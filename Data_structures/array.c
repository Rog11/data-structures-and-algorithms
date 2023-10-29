#define MAX_ARRAY_SIZE 100

int main() 
{
  int array[MAX_ARRAY_SIZE];
  int size = 0;

  // Insert new elements at the end of the array
  array[size] = 10;
  size++;
  array[size] = 20;
  size++;
  array[size] = 30;
  size++;

  // Access and modify elements of the array
  array[0] = 5;
  array[1] += 5;

  // Print the elements of the array
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");  // prints 5 25 30

  return 0;
}
