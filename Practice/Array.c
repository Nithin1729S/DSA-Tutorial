#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag=0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}


void insertionSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int x=A[i];
        int j=i-1;
        while(A[j]>x && j>-1)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

void selectionSort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k]) k=j;
        }
        swap(&A[i],&A[k]);
    }
}


void insertInHeap(int A[],int n)
{
    int i=n;
    int temp=A[n];
    while(i>1&&temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}



void deleteFromHeap(int A[],int n)
{
    int val=A[1];
    int x=A[n];
    A[1]=x;
    int i=1;
    int j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j]) j=j+1;
        if(A[i]<A[j])
        {
            swap(&A[i],&A[j]);
            i=j;
            j=2*j;
        }
        else break;
    }
    A[n]=val;
}

void heapSort(int A[],int n)
{
    for(int i=2;i<n;i++) insertInHeap(A,i);
    for(int i=n;i>1;i--) deleteFromHeap(A,i);
}


bool binarySearch(int A[],int n,int key)
{
    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(key==A[mid]) return true;
        else if(key>A[mid]) l=mid+1;
        else h=mid-1;
    }
    return false;
}

bool RBinarySearch(int A[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(A[mid]==key) return true;
        else if(key>A[mid]) return RBinarySearch(A,mid +1,h,key);
        else return RBinarySearch(A,l,mid-1,key);
    }
    return false;
}


int main()
{
    int A[]={0,99,1,2,6,1,45,1,0,90,45,25,9};
    int n=sizeof(A)/sizeof(int)-1;
    // printf("Enter the number of elements of the array: ");
    // scanf("%d", &n);
    // int *A = (int *)malloc(sizeof(int) * n);
    
    // if (A == NULL)
    // {
    //     printf("Memory allocation failed. Exiting...\n");
    //     return 1; 
    // }

    // printf("Enter the elements of the array:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &A[i]);
    // }
    
    heapSort(A, n);
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    // int x;
    // printf("\nEnter the element to be searched: ");
    // scanf("%d",&x);
    // printf("%s",RBinarySearch(A,0,n-1,x)?"True":"False");    
    // free(A);

    return 0;
}