#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    // Use a temporary variable to store the value of a
    int temp = *a;
    // Store the value of b in a
    *a = *b;
    // Store the value of temp (the original value of a) in b
    *b = temp;
}

// Max-heapify function
void maxHeapify(int arr[], int n, int i)
{
    // Initialize the largest element to be the element at the given index
    int largest = i;
    // Calculate the indices of the left and right children of the element
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If the left child exists and is greater than the largest element, set the largest element to be the left child
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // If the right child exists and is greater than the largest element, set the largest element to be the right child
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If the largest element is not the element at the given index, swap the two elements and call maxHeapify recursively on the index of the largest element
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Heapsort function
void heapSort(int arr[], int n)
{
    // Build the max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }

    // Extract elements from the heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Swap the first and last elements of the heap
        swap(&arr[0], &arr[i]);
        // Max-heapify the remaining elements
        maxHeapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[] = {5, 3, 8, 1, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using heapsort
    heapSort(arr, n);
    // Print the sorted array
    printArray(arr, n);  // Output: 1 3 5 6 8 9

    return 0;
}

