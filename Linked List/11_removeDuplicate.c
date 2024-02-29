#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertLast(struct Node **head,int x)
{
    
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    
    if(*head==NULL) 
    {
        *head=temp;
    }
    else
    {
        struct Node *p=*head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
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

void removeDuplicates(struct Node **head)
{
    struct Node *p=(*head)->next;
    struct Node *tail=*head;
    while(p)
    {
        if(p->data != tail->data)
        {
            tail=p;
            p=p->next;
        }
        else
        {
            tail->next=p->next;
            free(p);
            p=tail->next;
        }
    }
}

int main()
{
    struct Node *LL1=NULL;

    insertLast(&LL1,2);
    insertLast(&LL1,2);
    insertLast(&LL1,3);
    insertLast(&LL1,3);
    insertLast(&LL1,10);
    removeDuplicates(&LL1);
    display(LL1);

    return 0;

}