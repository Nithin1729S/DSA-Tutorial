#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void setArray(struct Array *arr,int A[],int size,int length)
{
    arr->A=(int*)malloc(sizeof(int)*size);
    arr->A=A;
    arr->length=length;
    arr->size=size;
}

void Display(struct Array arr)
{
    int i;
    printf("\nElements are \n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void InsertSort(struct Array *arr,int x)
{
    if(arr->length==arr->size) return;
    int i=arr->length-1;
    while(i>-1 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;

    }
    return 1;
}

void Reaarange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[i]>0) j--;
        if(i>j) swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{
    struct Array arr;
    int A[]={3,4,5,7,8,9,10};
    int n=sizeof(A)/sizeof(int);
    setArray(&arr,A,100,n);
    InsertSort(&arr,6);
    Display(arr);
    return 0;
}