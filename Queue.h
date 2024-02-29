#ifndef Queue_H
#define Queue_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue
{
    struct Queue* data;
    struct Queue *next;
};

void enqueue(struct Queue **head,int* x)
{
    struct Queue *temp=(struct Queue *)malloc(sizeof(struct Queue));
    temp->data=x;
    temp->next=NULL;

    if(*head==NULL) *head=temp;

    else
    {
        struct Queue *p=*head;
        while(p->next) p=p->next;
        p->next=temp;
    }
}

struct Node* dequeue(struct Queue **head)
{
    if (*head == NULL) return NULL;
    struct Queue *p = *head;
    *head = (*head)->next;
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = p->data;
    node->lChild = node->rChild = NULL;
    free(p);
    return node;
}


void display(struct Queue *head)
{
    struct Queue *p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

bool isEmpty(struct Queue *q)
{
    return q->next == NULL;
}

#endif