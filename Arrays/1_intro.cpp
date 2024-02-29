#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int A[5]={1,2,3,4,5};
    int *p;
    p=new int[5];
    p[0]=4;
    p[1]=5;
    p[2]=6;
    p[3]=7;
    p[4]=8;

    for(int i=0;i<5;i++)
    {
        printf("%d\n",A[i]);
    }

    for(int i=0;i<5;i++)
    {
        printf("%d\n",p[i]);
    }

    
    return 0;




}