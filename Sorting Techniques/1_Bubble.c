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

int main()
{
    int A[]={10,9,8,7,6,5,4};
    int n=7;
    bubbleSort(A,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}