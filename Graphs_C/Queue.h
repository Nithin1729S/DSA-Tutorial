#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>
//the code is using insert at head in LL...and also adj is array of structs
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=-1;
    q->rear=-1;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}

void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear) printf("Queue is Empty");
    else 
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}


int isEmpty(struct Queue *q)
{
    if(q->front==q->rear) return 1;
    else return 0;
}
#endif
