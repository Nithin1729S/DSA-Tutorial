#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};
typedef struct Node Node;

void insert(Node **p,int x,int y)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->coeff=x;
    temp->exp=y;
    temp->next=NULL;
    if(*p==NULL)
    {
        *p=temp;
    }
    else
    {   
        Node *q=*p;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=temp;
    }
}

Node * add(Node *poly1,Node*poly2)
{
    Node *result=NULL;
    while(poly1 && poly2)
    {
        if(poly1->exp==poly2->exp)
        {
            insert(&result,poly1->coeff+poly2->coeff,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->exp>poly2->exp)
        {
            insert(&result,poly1->coeff,poly1->exp);
            poly1=poly1->next;
        }
        else{
            insert(&result,poly2->coeff,poly2->exp);
            poly2=poly2->next;
        }
    }
    while(poly1)
    {
        insert(&result,poly1->coeff,poly1->exp);
        poly1=poly1->next;
    }
    while(poly2)
    {
        insert(&result,poly2->coeff,poly2->exp);
        poly2=poly2->next;
    }

    return result;
}

void print(Node*p)
{
    if(p==NULL)
    {
        printf("NULL");
        return;
    }
    else
    {
        Node* q=p;
        while(q)
        {
            printf("%dx^%d",q->coeff,q->exp);
            if(q->next!=NULL)
            {
                printf("+");
            }
            q=q->next;
        }
        
    }
}
int main()
{
    Node* poly1 = NULL;
    insert(&poly1, 5, 4);
    insert(&poly1, 3, 2);
    insert(&poly1, 1, 0);
    Node* poly2 = NULL;
    insert(&poly2, 4, 4);
    insert(&poly2, 2, 2);
    insert(&poly2, 1, 1);
    printf("First polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);
    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);
    return 0;
}
