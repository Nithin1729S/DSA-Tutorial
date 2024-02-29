#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *stk1 = NULL;
struct Stack *stk2= NULL;

void push(struct Stack **head, int x)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

int pop(struct Stack **head)
{
    int x;
    struct Stack *p = *head;
    (*head) = (*head)->next;
    x = p->data;
    free(p);
    return x;
}

int isEmpty(struct Stack *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack *head)
{
    int x = 0;
    if (head == NULL)
        return x;
    return (head->data);
}

void enqueue(int x)
{
    push(&stk1,x);
}

int dequeue()
{
    int x=-1;
    if(isEmpty(stk2))
    {
        if(isEmpty(stk1)) printf("Queue Empty");
        else
        {
            while(!isEmpty(stk1)) push(&stk2,pop(&stk1));
        }

    }
    return pop(&stk2);
}

int main()
{
    
}