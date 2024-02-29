#include<stdio.h>
void findDuplicates(int A[],int n)
{
    int j;
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            j=i+1;
            while(A[j]==A[i]) j++;
            printf("%d is repeated %d times.",A[i],j-i);
            i=j-1;
        }
    }
}

int main()
{
    int arr[]={6,7,8,8,9,11,12,15,16,17,18,19};
    int n=sizeof(arr)/sizeof(int);
    findDuplicates(arr,n);
    return 0;
}