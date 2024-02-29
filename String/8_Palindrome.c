#include<stdio.h>
#include<stdlib.h>
int main()
{
    char A[]="malayalam";
    char B[10];
    int i,j=0;
    for(i=0;A[i]!='\0';i++){}
    i=i-1;
    for(j=0;i>-1;i--,j++)
    {
        B[j]=A[i];
    }
    B[j]='\0';
    for(i=0,j=0;A[i]!='\0'&&B[j]!='\0';i++,j++)
    {
        if(A[i]!=B[j])
        {
            printf("Not a Palindrome.");
            return 0;
        }

    }
    printf("Palindrome");
    return 0;
}