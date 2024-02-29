#include<stdio.h>
#include<stdlib.h>

void insertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int x=A[i];
        int j=i-1;
        while(A[j]>x && j>-1)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main()
{
    int A[]={34,12,1,23,78};
    int n=4;
    insertionSort(A,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}