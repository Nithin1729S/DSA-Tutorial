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

void insertFirst(struct Node **head,int x)
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
        temp->next=*head;
        (*head)=temp;
    }
}

struct Node* merge(struct Node* head1, struct Node* head2)
{
    struct Node *p = head1;
    struct Node *q = head2;
    struct Node *third = NULL;
    struct Node *last = NULL;
    struct Node *temp;

    if (p->data < q->data)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = p->data;
        temp->next = NULL;
        last = third = temp;
        p = p->next;
    }
    else
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = q->data;
        temp->next = NULL;
        last = third = temp;
        q = q->next;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = p->data;
            temp->next = NULL;
            last->next = temp;
            last = temp;
            p = p->next;
        }
        else
        {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = q->data;
            temp->next = NULL;
            last->next = temp;
            last = temp;
            q = q->next;
        }
    }

    while (p)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = p->data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        p = p->next;
    }

    while (q)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = q->data;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        q = q->next;
    }

    return third;
}
       
struct Node *Rmerge(struct Node*h1,struct Node*h2)
{
    if(h1==NULL)return h2;
    if(h2==NULL) return h1;

    if(h1->data>=h2->data)
    {
        h2->next=Rmerge(h1,h2->next);
        return h2;
    }
    else
    {
        h1->next=Rmerge(h1->next,h2);
        return h1;
    }
    return NULL;
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

int main()
{
    struct Node *LL1=NULL;
    struct Node *LL2=NULL;
    struct Node *LL3=NULL;

    insertLast(&LL1,2);
    insertLast(&LL1,4);
    insertLast(&LL1,6);
    insertLast(&LL1,8);
    insertLast(&LL1,10);

    insertFirst(&LL2,9);
    insertFirst(&LL2,7);
    insertFirst(&LL2,5);
    insertFirst(&LL2,3);
    insertFirst(&LL2,1);
    
    LL3=Rmerge(LL1,LL2);
    
    
    display(LL3);

    return 0;

}