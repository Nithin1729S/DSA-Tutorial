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
    {
        printf("%d ",arr.A[i]);
    }
}

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length++]=x;
    }
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
    Append(&arr,10);
    Insert(&arr,2,199);
    Display(arr);
    return 0;




}