#include<stdio.h>

void findMissing(int arr[],int n)
{
    
    int diff=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]-i!=diff)
        {
            while(diff<arr[i]-i)
            {
                printf("%d ",i+diff);
                diff++;
            }
        }
    }
}
int main()
{
    int arr[]={6,7,8,9,11,12,15,16,17,18,19};
    int n=sizeof(arr)/sizeof(int);
    findMissing(arr,n);
    return 0;
}