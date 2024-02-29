#include<stdio.h>
#include<stdlib.h>

char* reverseStr(char* str,char* str2)
{
    int i,j=0;
    for(i=0;str[i]!='\0';i++)
    {}
    i=i-1;
    for(j=0;i>=0;i--,j++)
    {
        str2[j]=str[i];
    }
    str2[j]='\0';
    return str2;
}

int main()
{
    char A[]="python";
    char B[7];
    printf("The reversed string is %s\n",reverseStr(A,B));
    return 0;
}