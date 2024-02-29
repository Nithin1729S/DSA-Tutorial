#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int arr[],int n)
{
    struct Node *temp,*last;
    int i=0;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

void reverse(struct Node *p)
{
    int i=0;
    int *A=(int *)malloc(sizeof(int)*count(p));
    struct Node *q=p;
    while(q)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node*q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Rreverse(struct Node *q,struct Node *p)
{
    if(p)
    {
        Rreverse(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    //printf("%llu \n",sizeof(arr)/sizeof(int));
    create(arr,n);
    display(first);
    reverse(first);
    printf("\n");
    display(first);
    reverse2(first);
    printf("\n");
    display(first);
    Rreverse(NULL,first);
    printf("\n");
    display(first);
    return 0;
}

