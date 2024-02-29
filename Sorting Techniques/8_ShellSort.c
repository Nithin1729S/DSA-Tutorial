#include <stdio.h>
#include <stdlib.h>

void ShellSort(int A[], int n)
{
    int gap, i, j,temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (A[j] > temp && j >-1)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        int j = i - 1;
        while (A[j] > x && j > -1)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int A[] = {11, 1, 2, 5, 6, 3, 43, 56, 23, 21, 7};
    int n = sizeof(A) / sizeof(int);

    ShellSort(A, n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}