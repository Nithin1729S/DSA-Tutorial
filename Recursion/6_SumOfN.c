#include <stdio.h>
#include <stdlib.h>


int sum(int n)
{
    if(n==0) return 0;
    else return sum(n-1)+n;
}

int main()
{
    int n=5;
    int res=sum(n);
    printf("%d ",res);
    return 0;
}