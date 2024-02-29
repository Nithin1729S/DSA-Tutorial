#include<stdio.h>
#include<stdlib.h>
//#include "Queue.h"

struct Node
{
    int data;
    struct Node *next;
};

void enqueue(struct Node **head,int x)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;

    if(*head==NULL) *head=temp;

    else
    {
        struct Node *p=*head;
        while(p->next) p=p->next;
        p->next=temp;
    }
}

int dequeue(struct Node **head)
{
    int x;
    struct Node *p=*head;
    *head=(*head)->next;
    x=p->data;
    free(p);
    return x;

}

void display(struct Node *head)
{
    struct Node *p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *q1=NULL;
    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);

    display(q1);

}
