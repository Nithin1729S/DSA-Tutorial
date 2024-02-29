#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int Delete(struct Array *arr,int idx)
{
    int x=-1;
    if(idx>=0 && idx<arr->length)
    {
        x=arr->A[idx];
        for(int i=idx;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
    }
    return x;
}

void Insert(struct Array *arr,int idx,int x)
{
    if(idx>=0 && idx<=arr->length)
    {
        for(int i=arr->length;i>idx;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[idx]=x;
        arr->length++;
    }
}

int main()
{
    struct Array arr={{1,2,34,5,0},10,5};
    Delete(&arr,1);
    Display(arr);
    return 0;
}