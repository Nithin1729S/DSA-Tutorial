#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head,int x)
{
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
    temp->next=*head;
    *head=temp;
    }
}

void display(struct Node *head)
{
    struct Node*p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int pop(struct Node**head)
{
    struct Node *t=*head;
    int x=-1;
    if(t==NULL)
        printf("Stack is Empty.\n");
    else
    {
        *head=(*head)->next;
        x=t->data;
        free(t);
    }
    return x;
}

int main()
{
    struct Node*head=NULL;
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,0);
    push(&head,1);
    pop(&head);
    display(head);
    return 0;

}