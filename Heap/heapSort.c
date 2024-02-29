#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insert(int A[],int n)
{
    int i=n;
    int temp=A[i];
    while( i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void delete(int A[],int n)
{
    int val=A[1];
    int x=A[n];
    A[1]=x;
    int i=1;
    int j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j]) j=j+1;
        if(A[i]<A[j])
        {
            swap(&A[i],&A[j]);
            i=j;
            j=2*j;
        }
        else break;
    }
    A[n]=val;
}

int main()
{
    int A[]={0,67,45,3,5,98,12,67,87};
    for(int i=2;i<=8;i++) insert(A,i);
    for(int i=1;i<8;i++) printf("%d ",A[i]);
    printf("\n");
    for(int i=8;i>1;i--) delete(A,i);
    for(int i=1;i<8;i++) printf("%d ",A[i]);
    return 0;
}