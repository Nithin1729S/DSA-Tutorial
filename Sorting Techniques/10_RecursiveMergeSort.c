#include <stdio.h>
#include <stdlib.h>


void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j]) B[k++] = A[i++];
        else B[k++] = A[j++];
    }
    for (; i <= mid; i++) B[k++] = A[i];
    for (; j <= h; j++) B[k++] = A[j];
    for (i = l; i <= h; i++) A[i] = B[i];
}

void mergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}

int main()
{
    int A[] = {11, 5, 14, 2, 6, 3, 1}, i;
    int n=7;
    mergeSort(A, 0,n-1);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}