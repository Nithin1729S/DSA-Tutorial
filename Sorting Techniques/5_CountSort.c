#include<stdio.h>
#include<stdlib.h>


int findMax(int A[],int n)
{
    int max=A[0];
    for(int i=0;i<n;i++)
    {
        if(A[i]>max) max=A[i];
    }
    return max;
}

void countSort(int A[],int n)
{
    int i,j,max,*C;
    max=findMax(A,n);
    C=(int*)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++) C[i]=0;
    for(i=0;i<n;i++) C[A[i]]++;
    j=0;
    i=0;
    while(i<max+1)
    {
        if(C[i]>0)
        {
            A[j++]=i;
            C[i]--;
        }
        else i++;
    }
}

int main()
{
    int A[]={11,1,2,5,6,3,43,56,23,21,7};
    int n=sizeof(A)/sizeof(int);
    
    countSort(A,n);

    for(int i=0;i<n;i++) printf("%d ",A[i]);
    return 0;
}