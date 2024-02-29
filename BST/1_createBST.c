#include <stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Insert(int key)
{
    struct Node*t=root;
    struct Node*r,*p;
    if(root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data) t=t->lchild;
        else if(key>t->data) t=t->rchild;
        else return;
    }//now t is null but r is just before it...
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;
}

void Inorder(struct Node*p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

struct Node* search(int key)
{
    struct Node *t=root;
    while(t)
    {
        if(key==t->data) return t;
        else if(key<t->data) t=t->lchild;
        else t=t->rchild;
    }
    return NULL;
}

int main()
{
    Insert(9);
    Insert(15);
    Insert(5);
    Insert(20);
    Insert(16);
    Insert(8);
    Insert(12);
    Insert(3);
    Insert(6);
    Inorder(root);

    struct Node*temp;
    temp=search(2);
    if(temp) printf("\nelement %d is found.",temp->data);
    else printf("\nelement is not found.");
    return 0;
}
