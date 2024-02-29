#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int arr[],int n)
{
    int i;
    struct Node *temp,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void sortedCheck(struct Node *p)
{
    int x=-65536;
    while(p)
    {
        if(p->data<x)
        {
            printf("The Linked List is not Sorted.");
            return;
        }
        x=p->data;
        p=p->next; 
    }
    printf("The Linked List is sorted.");
}

int main()
{
    int arr[]={1,2,9,4,5};
    int n=5;
    create(arr,n);
    display(first);
    sortedCheck(first);
    return 0;
}