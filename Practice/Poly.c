#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

void insert(struct Node **head,int coeff,int exp)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->coeff=coeff;
    temp->exp=exp;
    temp->next=NULL;
    if(*head==NULL) *head=temp;
    else
    {
        struct Node *p=*head;
        while(p->next) p=p->next;
        p->next=temp;
    }
}


struct Node* addPoly(struct Node *poly1,struct Node *poly2)
{
    struct Node *res=NULL;
    while(poly1&&poly2)
    {
        if(poly1->exp==poly2->exp)
        {
            insert(&res,poly1->coeff+poly1->coeff,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->exp>poly2->exp)
        {
            insert(&res,poly1->coeff,poly1->exp);
            poly1=poly1->next;
        }
        else
        {
            insert(&res,poly2->coeff,poly2->exp);
            poly2=poly2->next;
        }
        
    }
    while(poly1)
    {
        insert(&res,poly1->coeff,poly1->exp);
        poly1=poly1->next;
    }
    while(poly2)
    {
        insert(&res,poly2->coeff,poly2->exp);
        poly2=poly2->next;
    }
    return res;
}

struct Node* mulPoly(struct Node *poly1,struct Node *poly2)
{
    struct Node *res=NULL;
    struct Node *p=poly1;
    while(p)
    {
        struct Node *q=poly2;
        while(q)
        {
            int cf=p->coeff*q->coeff;
            int ex=p->exp+q->exp;
            insert(&res,cf,ex);
            q=q->next;
        }
        p=p->next;
    }
    return res;
}


void display(struct Node *head)
{
    struct Node *p=head;
    while(p)
    {
        if(p->exp==0) printf("%d",p->coeff);
        if(p->exp==1) printf("%dx",p->coeff);
        else printf("%dx^%d",p->coeff,p->exp);
        if(p->next!=NULL) printf("+");
        p=p->next;
    }
    printf("\n");
}

int main()
{
    struct Node * poly1=NULL;
    insert(&poly1,9,2);
    insert(&poly1,3,1);
    struct Node *poly2=NULL;
    insert(&poly2,3,1);
    struct Node *res=mulPoly(poly1,poly2);
    display(res);
    return 0;

}