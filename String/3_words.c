#include<stdio.h>
#include<stdlib.h>

int countWords(char *str)
{
    int i=0,count=1;

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ' && str[i-1]!=' ')
            count++;
    }
    return count;
}

void main()
{
    char* sentence="Hi! How   are   you?";
    printf("The number of words in the string is %d",countWords(sentence));
}