#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

void createLL(Node**head,int n)
{
    while(n!=0)
    {
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=n%10;
    temp->next=NULL;
    if(*head==NULL) *head=temp;
    else
    {
        Node*last=*head;
        while(last->next!=NULL)
            last=last->next;
        last->next=temp;
    }
    n=n/10;
    }
}

void reverse(Node **p)
{
    Node *r=NULL,*q=NULL;
    while(*p)
    {
        r=q;
        q=*p;
        *p=(*p)->next;
        q->next=r;
    }
    *p=q;
}

void print(Node *p) {
    if (p == NULL) {
        printf("No Number");
        return;
    } else {
        while (p) {
            printf("%d", p->data);
            p = p->next;
        }
    }
}

Node* add(Node *num1,Node*num2)
{
    if(num1->data==0)
        return num1;
    if(num2->data==0)
        return num2;
    Node *p=num1;
    Node *q=num2;
    Node *res=NULL;
    int carry=0,sum=0;
    while(p||q)
    {
        sum=0;
        if(p) sum+=p->data;
        if(q) sum+=q->data;
        sum+=carry;
        carry=sum/10;
        sum%=10;
        createLL(&res,sum);
        if(p) p=p->next;
        if(q) q=q->next;
    }
    if(carry)
        createLL(&res,carry);
    return res;
}

int main()
{
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    Node* NUM1=NULL;
    Node* NUM2=NULL;
    Node* Res=NULL;
    createLL(&NUM1,num1);
    createLL(&NUM2,num2);
    Res=add(NUM1,NUM2);
    reverse(&Res);
    print(Res);

    
    return 0;

}
