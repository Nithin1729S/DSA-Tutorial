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

int linearSearch(struct Array *arr,int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
            
    }
    return -1;
}

int main()
{
    struct Array arr={{1,2,3,4,5,6},6,20};
    Display(arr);
    printf("\n%d\n",linearSearch(&arr,4));
    Display(arr);
    printf("\n%d\n",linearSearch(&arr,6));
    Display(arr);
    return 0;
}   