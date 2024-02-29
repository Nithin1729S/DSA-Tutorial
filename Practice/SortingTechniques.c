#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int A[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                flag=1;
                swap(&A[j+1],&A[j]);
            }
        }
        if(flag==0) break;
    }
}

void insertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=A[i];
        int j=i-1;
        while(j>-1 && A[j]>temp)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
}

void shellSort(int A[],int n)
{
    int gap,temp,i,j;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>-1 && A[j]>temp)
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
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

void merge(int A[],int l,int mid,int h)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int B[100];

    while(i<=mid&& j<=h)
    {
        if(A[i]<A[j]) B[k++]=A[i++];
        else B[k++]=A[j++];
    }
    for(;i<=mid;i++) B[k++]=A[i];
    for(;j<=h;j++) B[k++]=A[j];
    for(i=l;i<=h;i++) A[i]=B[i];
}


void mergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}


int partition(int A[],int l,int h)
{
    int i=l;
    int j=h;
    int pivot=A[l];
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j) swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;
}

void quickSort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j+1,h);
    }
}

int findMax(int A[],int n)
{
    int max=A[0];
    for(int i=0;i<n;i++)
    {
        if(A[i]>max) max=A[i];
    }
    return max;
}

void countSort(int A[],int n)
{
    int i,j,max,*C;
    max=findMax(A,n);
    C=(int*)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++) C[i]=0;
    for(i=0;i<n;i++) C[A[i]]++;
    j=0;
    i=0;
    while(i<max+1)
    {
        if(C[i]>0)
        {
            A[j++]=i;
            C[i]--;
        }
        else i++;
    }
}

int main()
{
    int A[] = {11, 1, 2, 5, 6, 3, 43, 56, 23, 21, 7};
    int n = sizeof(A) / sizeof(int);

    //mergeSort(A,0,n-1); //last index passed at end
    quickSort(A,0,n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}