#include<bits/stdc++.h>
using namespace std;

class SortingALgos
{
    public:
        void mergeArr(int arr[],int l,int mid,int h)
        {
            int B[100];
            int i=l;
            int j=mid+1;
            int k=l;
            while(i<=mid && j<=h)
            {
                if(arr[i]>arr[j]) B[k++]=arr[j++];
                else B[k++]=arr[i++];
            }
            for(;i<=mid;i++) B[k++]=arr[i];
            for(;j<=h;j++) B[k++]=arr[j];
            for(int i=l;i<=h;i++) arr[i]=B[i];


        }
        void mergeSort(int arr[],int l,int h)
        {
            if(l<h)
            {
                int mid=(l+h)/2;
                mergeSort(arr,l,mid);
                mergeSort(arr,mid+1,h);
                mergeArr(arr,l,mid,h);
            }
        }
};

int main()
{
    SortingALgos sol;
    int arr1[]={1,4,2,3,5,2,9,0,2};
    sol.mergeSort(arr1,0,sizeof(arr1)/sizeof(arr1[0]));
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
    {
        cout<<arr1[i]<<" ";
    }
    return 0;

}