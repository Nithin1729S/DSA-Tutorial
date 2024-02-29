#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first,*temp,*last=NULL;


void create(int arr[],int n)
{
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void Display(struct Node*p)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void Insert(struct Node *p,int pos,int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        for(int i=0;i<pos-1&&p;i++)
            p=p->next;
        if(p)
        {
            t->next=p->next;
            p->next=t;
        }
    }
}

int main()
{
    int A[]={1,2,3};
    int n=3;
    create(A,n);
    Display(first);
    Insert(first,0,100);
    Display(first);
    Insert(first,2,111);
    Display(first);
    return 0;
}