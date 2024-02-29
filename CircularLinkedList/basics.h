#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


void create(struct Node**head,int A[],int n)
{
    struct Node *t,*last;
    *head=(struct Node*)malloc(sizeof(struct Node));
    (*head)->data=A[0];
    (*head)->next=*head;  //circular
    last=*head;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;  //not NULL
        last->next=t;
        last=t;
    }

}

void display(struct Node*head)
{
    struct Node* p=head;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=head); 
    printf("\n");
}

void RDisplay(struct Node *head)
{
    struct Node *p=head;
    static int flag=0;
    if(p!=head ||flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        RDisplay(p->next);
    }
    flag=0;
}

int count(struct Node*head)
{
    int count=0;
    struct Node*p=head;
    do
    {
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}

void insert(struct Node **head,int idx,int x)
{
    if(idx<0||idx>count(*head)) return;
    struct Node *p=*head;
    struct Node*t;
    if(idx==0)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        if(*head==NULL) //first node
        {
            *head=t;
            (*head)->next=*head;
        }
        else
        {
            while(p->next!=*head) p=p->next;
            p->next=t;
            t->next=*head;
            *head=t;

        }
        
    }

    else
    {
        for(int i=0;i<idx-1;i++)
        {
            p=p->next;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }


}

int delete(struct Node **head,int idx)
{
    struct Node *p=*head;
    struct Node *q;
    int x;
    if(idx<0 || idx>=count(*head))  return -1;
    if(idx==0)
    {
        while(p->next!=*head) p=p->next;
        x=(*head)->data;
        if(*head==p)  //only one node
        {
            free(*head);
            *head=NULL;
        }
        else
        {
            p=p->next=(*head)->next;
            x=(*head)->data;
            free(*head);
            *head=p->next;
        }
    }
    else
    {
        for(int i=0;i<idx-1;i++)
        {
            p=p->next;  //points just before the node to be deleted
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}


int main()
{
    struct Node* head=NULL;
    int A[]={1,2,43,5,6,7};
    int n=6;
    create(&head,A,n);
    display(head);
    display(head);
    return 0;

}