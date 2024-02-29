#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void maxHeapify(int A[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        int j=2*i;
        while(j<=n-1)
        {
            if(A[j+1]>A[j]) j=j+1;
            if(A[i]<A[j])
            {
                swap(&A[i],&A[j]);
                i=j;
                j=2*i;
            }
            else break;
        }

    }
}
int main()
{
    int A[]={6,12,5,10,20,30,15};
    int n=7;
    maxHeapify(A,n);
    for(int i=1;i<n;i++) printf("%d ",A[i]);
    return 0;
}