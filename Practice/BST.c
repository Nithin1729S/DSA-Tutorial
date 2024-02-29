#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node*lChild;
    int data;
    struct Node *rChild;
};

void insert(struct Node **root,int key)
{
    struct Node *temp=*root,*tail;

    while(temp)
    {
        tail=temp;
        if(key==temp->data) return;
        else if(key<temp->data) temp=temp->lChild;
        else temp=temp->rChild;
    }
    struct Node*p=(struct Node*)malloc(sizeof(struct Node*));
    p->data=key;
    p->rChild=p->lChild=NULL;
    if(p->data>tail->data) tail->rChild=p;
    else tail->lChild=p;
}

struct Node *Rinsert(struct Node*p,int key)
{
    if(p==NULL)
    {
        struct Node *temp=NULL;
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=key;
        temp->lChild=temp->rChild=NULL;
        return temp;
    }
    if(key>p->data) p->rChild=Rinsert(p->rChild,key);
    else if(key<p->data) p->lChild=Rinsert(p->lChild,key);
    return p;
}

struct Node * delete(struct Node *p,int key)
{
    
}

int main()
{
    struct Node *bst1=NULL;

}