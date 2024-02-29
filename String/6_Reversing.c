#include<stdio.h>
#include<stdlib.h>
int main()
{
    char A[]="Mr. Bruh";
    char temp;
    int i,j=0;
    for(i=0;A[i]!='\0';i++)
    {}
    i=i-1;
    for(j=0;j<i;i--,j++)
    {
        temp=A[j];
        A[j]=A[i];
        A[i]=temp;
    }
    printf("The reversed string is %s\n",A);
    return 0;
}