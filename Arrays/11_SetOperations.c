#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[100];
    int size;
    int length;
};

struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i])arr3->A[k++]=arr2->A[j++];
        else 
        {
        arr3->A[k++]=arr1->A[i++];
        j++;
        }

    }
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i++];
    for(;j<arr2->length;j++) arr3->A[k++]=arr2->A[j++];
    arr3->length=k;
    arr3->size=100;

    return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]) i++;
        else if (arr2->A[j]<arr1->A[i]) j++;
        else if (arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=100;

    return arr3;
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


struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array*)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]) arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j]<arr1->A[i]) j++;   //no need to copy elements of second array
        else 
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++) arr3->A[k++]=arr1->A[i++];
    arr3->length=k;
    arr3->size=100;
    return arr3;
}

int main()
{
    struct Array arr1={{1,3,5,7,9},100,5};
    struct Array arr2={{2,3,4,6,8,10},100,5};
    struct Array *arr3;
    struct Array *arr4;
    struct Array *arr5;
    arr3=Union(&arr1,&arr2);
    arr4=Intersection(&arr1,&arr2);
    arr5=Difference(&arr1,&arr2);

    Display(*arr3);
    Display(*arr4);
    Display(*arr5);

    return 0;



}