#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertLast(struct Node**head,int x)
{
    struct Node *p=*head;
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(p==NULL)
    {
        *head=temp;
    }
    else
    {
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

void display(struct Node *head)
{
    struct Node *p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

struct Node* addNum(struct Node *h1,struct Node *h2)
{
    struct Node*p=h1;
    struct Node*q=h2;
    struct Node *res=NULL;
    int carry=0;int sum=0;
    while(p||q)
    {
        sum=0;
        if(p) sum+=p->data;
        if(q) sum+=q->data;
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        insertLast(&res,sum);
        if(p) p=p->next;
        if(q) q=q->next;
    }
    if(carry)
        insertLast(&res,carry);
    return res;
}


void reverse(struct Node**head)
{
    struct Node *p=*head;
    struct Node *q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *head=q;
}

int main()
{
    struct Node *num1=NULL;
    struct Node *num2=NULL;
    struct Node *res=NULL;
    int n1,n2;
    printf("Enter a number 1: ");
    scanf("%d",&n1);
    while(n1>0)
    {
        int dig=n1%10;
        insertLast(&num1,dig);
        n1=n1/10;
    }
    printf("Enter a number 2: ");
    scanf("%d",&n2);
    while(n2>0)
    {
        int dig=n2%10;
        insertLast(&num2,dig);
        n2=n2/10;
    }
    display(num1);
    display(num2);

    printf("Adding these two numbers gives: ");
    res=addNum(num1,num2);
    reverse(&res);
    display(res);
    return 0;
}