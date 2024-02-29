#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    int *p,*q;
    p=new int[5];
    for(int i=0;i<5;i++)
    {
        p[i]=2*i;
    }

    for(int i=0;i<5;i++)
    {
        printf("%d\n",p[i]);
    }

    q=new int[10];
    for(int i=0;i<10;i++)
    {
        q[i]=p[i];
    }

    delete []p;

    p=q;
    q=NULL;
    for(int i=0;i<5;i++)
    {
        printf("%d\n",q[i]);
    }

    return 0;




}