#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void enqueue(struct Node **front, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if (*front == NULL)
    {
        *front = t;
        // If the queue was empty, the front and rear point to the same node.
    }
    else
    {
        struct Node *rear = *front;
        while (rear->next) rear = rear->next;
        rear->next = t;
    }
}

int dequeue(struct Node **front)
{
    int x = -1;
    struct Node *t;
    if (*front == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        x = (*front)->data;
        t = *front;
        *front = (*front)->next;
        free(t);
    }
    return x;
}

void Display(struct Node *head)
{
    struct Node *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *front = NULL;
    enqueue(&front, 10);
    enqueue(&front, 20);
    enqueue(&front, 30);
    enqueue(&front, 40);
    Display(front);
    printf("%d",dequeue(&front));
    printf("\n");
    Display(front);

    return 0;
}
