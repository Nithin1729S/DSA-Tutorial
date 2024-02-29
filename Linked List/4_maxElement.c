#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*temp=NULL,*last=NULL;


void createLL(int arr[],int n)
{
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }

}

int maxEle(struct Node *p)
{
    int max=-32000;
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }   
    return max;

}



int main()
{
    int A[]={1,2,3,5,6,78};
    int n=6;
    createLL(A,6);
    printf("Max is %d",maxEle(first));
    return 0;


}