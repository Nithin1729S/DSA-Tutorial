#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int A[], int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if the left child is larger than the current largest
    if (left < heapSize && A[left] > A[largest])
        largest = left;

    // Check if the right child is larger than the current largest
    if (right < heapSize && A[right] > A[largest])
        largest = right;

    // If the largest element is not the current element (i), swap them
    if (largest != i) {
        swap(&A[i], &A[largest]);

        // Recursively call MAX-HEAPIFY on the affected subtree
        maxHeapify(A, heapSize, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    int lastNonLeafNode = (n / 2) - 1;
    // Perform level order traversal in reverse from last non-leaf node to the root node and heapify each node
    for (int i = lastNonLeafNode; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int A[], int length) {
    buildMaxHeap(A, length);

    for (int i = length - 1; i >= 1; i--) {
        // Swap the root (maximum element) with the last element
        swap(&A[0], &A[i]);

        // Reduce the heap size
        length--;

        // Heapify the remaining elements
        maxHeapify(A, length, 0);
    }
}

int extractMax(int A[], int *heapSize) {
    if (*heapSize <= 0) {
        printf("Heap is empty. Cannot extract maximum element.\n");
        return -1; // Return a sentinel value indicating an error
    }

    int max = A[0]; // The maximum element is at the root of the max-heap

    // Replace the root with the last element in the heap
    A[0] = A[*heapSize - 1];

    // Reduce the heap size
    (*heapSize)--;

    // Restore the max-heap property by calling MAX-HEAPIFY on the root
    maxHeapify(A, *heapSize, 0);

    return max;
}

void insertIntoMaxHeap(int A[], int *heapSize, int newValue) {
    if (*heapSize >= sizeof(A) / sizeof(A[0])) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    // Insert the new value at the end of the array
    A[*heapSize] = newValue;

    // Increase the heap size
    (*heapSize)++;

    // Restore the max-heap property by calling MAX-HEAPIFY on the newly added element
    maxHeapify(A, *heapSize, (*heapSize - 1));
    
}

void increaseKey(int A[], int index, int newValue) {
    if (newValue < A[index]) {
        printf("New value is smaller than the current value. Cannot increase key.\n");
        return;
    }

    A[index] = newValue;

    // Use MAX-HEAPIFY to restore the max-heap property
    maxHeapify(A, index + 1, index);
}


int main() {
    int A[] = {4, 10, 3, 5, 1};
    int heapSize = 5;

    buildMaxHeap(A,heapSize);
    heapSort(A,heapSize);
    extractMax(A,&heapSize);
    printf("\nMax-Heapified Array: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
