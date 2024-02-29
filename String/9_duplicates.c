#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void findDuplicates(char *str)
{
    int H[26]={0};
    for(int i=0;str[i]!='\0';i++)
        H[str[i]-97]++;
    for(int i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            printf("The letter %c is repeated %d times.\n",i+97,H[i]);
        }
    }
}
int main()
{
    char* A="nithin";
    findDuplicates(A);

}