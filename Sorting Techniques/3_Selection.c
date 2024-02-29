#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void SelectionSort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[i],&A[k]);
    }
}

int main()
{
    int A[]={22,1,2,34,0,9,1};
    int n=7;
    selectionSort(A,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}