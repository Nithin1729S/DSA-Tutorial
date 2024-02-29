#include<stdio.h>
#include<stdlib.h>

struct Array 
{
    int A[20];
    int length;
    int size;
};


void Display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int  binarySearch(struct Array arr,int key)
{
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int RBinarySearch(struct Array arr,int l,int h ,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            return RBinarySearch(arr,l,mid-1,key);
        else
            return RBinarySearch(arr,mid+1,h,key);

    }
    return -1;

}

int main()
{
    struct Array arr={{1,2,3,4,5,6},6,20};
    Display(arr);
    printf("\n%d\n",binarySearch(arr,4));
    Display(arr);
    printf("\n%d\n",RBinarySearch(arr,0,arr.length,4));
    
    return 0;
} 