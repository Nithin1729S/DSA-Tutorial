#include<stdio.h>
#include<stdlib.h>

void validate(char* str)
{
    int i=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(!((str[i]>'A' && str[i]<'Z')||(str[i]>'a' && str[i]<'z')))
        {
            printf("The Name is Invalid");
            return;
        }
    }
    printf("Valid Name");
}

int main()
{
    char *name="Nithin S";
    validate(name);
    return 0;
}