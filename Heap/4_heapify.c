#include <stdio.h>

void swap(int* a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Heapify(int A[], int n) {
    for (int i = (n / 2) - 1; i >= 1; i--) {

        int j = 2 * i; // Left child for current i

        while (j < n - 1) {
            // Compare left and right children of current i
            if (A[j] < A[j + 1]) {
                j = j + 1;
            }

            // Compare parent and largest child
            if (A[i] < A[j]) {
                swap(&A[i],&A[j]);
                i = j;
                j = 2 * i;
            } else {
                break;
            }
        }
    }
}

int main() {

    int A[] = {0, 5, 10, 30, 20, 35, 40, 15};
    for(int i=8;i>1;i--) Heapify(A,i);
    for(int i=1;i<8;i++) printf("%d ",A[i]);

    return 0;
}
