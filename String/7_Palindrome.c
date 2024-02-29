#include<stdio.h>
#include<stdlib.h>
int main()
{
    char A[]="maam";
    int i,j=0;
    for(i=0;A[i]!='\0';i++){}
    i=i-1;
    for(j=0;j<i;j++,i--)
    {
        if(A[i]!=A[j]) 
        {
            printf("Not a Palindrome!!\n");
            return 0;
        }
    }
    printf("Palindrome\n");
    return 0;
}