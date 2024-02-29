#include<stdio.h>
#include<stdlib.h>
void main()
{
    int x=5;
    fun(x-1);
}


void fun(int n)
{
    if(n>0)
    {
        fun(n-1);
        printf("%d",n);
        
        
    }
}

