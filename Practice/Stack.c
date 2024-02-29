#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head,int x)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=*head;
    *head=temp;
}

int pop(struct Node **head)
{
    int x;
    struct Node *p=*head;
    (*head)=(*head)->next;
    x=p->data;
    return x;
}

void display(struct Node *head)
{
    struct Node *p=head;
    if(p)
    {
        printf("%d ",p->data);
        display(p->next);
    }
}


int main()
{
    struct Node *stk1=NULL;
    push(&stk1,1);
    push(&stk1,2);
    push(&stk1,3);
    push(&stk1,4);
    push(&stk1,5);
    pop(&stk1);
    pop(&stk1);
    pop(&stk1);
    display(stk1);

}