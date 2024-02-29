#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int* Q;
};

void create(struct Queue *q)
{
    int n;
    q->front = -1; 
    q->rear = -1;
    printf("Enter the size of the queue: ");
    scanf("%d",&n);
    q->size=n;
    q->Q=(int*)malloc(sizeof(int)*n);
}

void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front) printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    {
        printf("Queue is Empty");
        return -1;
    }
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int peek(struct Queue q)
{
    return q.Q[q.front+1];
}

void display(struct Queue q)
{

    if(q.rear==q.front)
    {
        printf("Queue is Empty");
        return;
    }
    int i=q.front+1;
    while (i != (q.rear + 1) % q.size)
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q);
    enqueue(&q, 10);
    enqueue(&q, 1);
    enqueue(&q, 0);
    enqueue(&q, 17);
    enqueue(&q, 19);
    dequeue(&q);
    int peekValue = peek(q);
    if (peekValue != -1)
    {
        printf("Peek value: %d\n", peekValue);
    }
    display(q);
    return 0;
}