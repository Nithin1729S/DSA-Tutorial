#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;

    }
}

void InsertLast(struct Node **head,int x)
{
    struct Node *p=*head;
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(p==NULL)
    {
        *head=temp;
        return;
    }
    while(p->next)
    {
        p=p->next;
    }
    p->next=temp;
}

int main()
{
    struct Node *LL1=NULL;
    InsertLast(&LL1,10);
    InsertLast(&LL1,11);
    InsertLast(&LL1,12);
    InsertLast(&LL1,13);
    Display(LL1);
    return 0;
}