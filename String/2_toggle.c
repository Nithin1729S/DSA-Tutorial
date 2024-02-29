#include<stdio.h>
#include<stdlib.h>
int main()
{
    char A[]="W!LComE";
    int i;
    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<=90)
            A[i]+=32;
        else if (A[i]>='a' && A[i]<='z')
            A[i]-=32;
        
    }

    printf("%s",A);
    return 0;
}