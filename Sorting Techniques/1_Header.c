#include<stdio.h>
#include<stdlib.h>


void swap(int*x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubbleSort(int A[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {   
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                flag=1;
                swap(&A[j],&A[j+1]);
            }
        }
        if(flag==0)
        break;
    }
}

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