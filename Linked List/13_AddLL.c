#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node** LL,int data)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // or handle the error in an appropriate way
    }
    temp->data=data;
    temp->next=NULL;
    if(*LL==NULL)  //ie if the stack is still empty
    {
        *LL=temp;
    }
    else
    {
        struct Node *p;
        p=*LL;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

void print(struct Node *p)
{
    if(p==NULL) 
    {
        printf("0\n");
        return;
    }
    struct Node *q=p;
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}

struct Node *add(struct Node *p,struct Node *q)
{
    struct Node *result=NULL;
    while(p && q)
    {
        insert(&result,p->data+q->data);
        p = p->next;
        q = q->next;
    }

    return result;
}


int main()
{
    struct Node* LL1=NULL;
    struct Node* LL2=NULL;
    struct Node* res=NULL;
    insert(&LL1,2);
    insert(&LL1,3);
    insert(&LL1,5);
    insert(&LL2,1);
    insert(&LL2,2);
    insert(&LL2,8);
    print(LL1);
    printf("\n");
    print(LL2);
    printf("\n");
    res=add(LL1,LL2);
    print(res);
    return 0;




}

