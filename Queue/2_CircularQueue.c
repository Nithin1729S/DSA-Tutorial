#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue*q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}

void enqueue(struct Queue *q,int x)
{
    if((q->rear+1)%q->size==q->front) printf("Queue is Full");
    else
    {
        q->rear=((q->rear+1)%q->size);
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->front) printf("Queue is full");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void display(struct Queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;

    }while(i!=(q.rear+1)%q.size);

}

int main()
{
    struct Queue q;
    int n;
    printf("Enter the size of the queue: ");
    scanf("%d",&n);
    create(&q,n);


}