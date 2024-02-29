#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int*Q;
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
    if(q->rear==q->size-1) printf("Queue is full");
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
    
}

void dequeue(struct Queue *q)
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


void display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    int n=5;
    // printf("Enter the size of the queue: ");
    // scanf("%d",&n);
    create(&q,n);

    enqueue(&q,10);
    enqueue(&q,1);
    enqueue(&q,0);
    enqueue(&q,17);
    enqueue(&q,19);
    dequeue(&q);
    display(q);
}