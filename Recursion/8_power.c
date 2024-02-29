#include <stdio.h>
#include <stdlib.h>

int power(int m,int n)
{
    if(n==0) return 1;
    if(n%2==0) return pow(m*m,n/2);
    else return m*pow(m,(n-1)/2);
}


