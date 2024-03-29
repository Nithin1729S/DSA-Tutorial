#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l;
    int j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j) swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}

void QuickSort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}


int main()
{
    int A[]={1,5,1,2,4,5,98,1,2,3,__INT_MAX__};
    int n=11;
    int i;
    QuickSort(A,0,10);
    for(int i=0;i<10;i++)
        printf("%d ",A[i]);
    return 0;
}