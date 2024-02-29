#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(sizeof(int) * size);
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        q->front++;
        return q->Q[q->front];
    }
}

void display(struct Queue q)
{
    for (int i = (q.front + 1); i < q.rear+1; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int peek(struct Queue q)
{
    if (q.front == q.rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q.Q[q.front + 1];
}

int main()
{
    struct Queue q;
    int n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    create(&q, n);
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
