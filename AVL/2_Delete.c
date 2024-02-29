#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lChild;
    int data;
    int height;
    struct Node* rChild;
}*root=NULL;

int nodeHeight(struct Node *p)
{
    int hl,hr;
    hl=(p&&p->lChild)?p->lChild->height:0;
    hr=(p&&p->rChild)?p->rChild->height:0;
    return (hl>hr)?hl+1:hr+1;
}

int balanceFactor(struct Node *p)
{
    int hl,hr;
    hl=(p&&p->lChild)?p->lChild->height:0;
    hr=(p&&p->rChild)?p->rChild->height:0;
    return hl-hr;
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lChild);
        printf("%d ",p->data);
        inorder(p->rChild);
    }
}

struct Node* LLrotation(struct Node *p)
{
    

}

struct Node* RRrotation(struct Node *p)
{

}

struct Node* LRrotation(struct Node *p)
{

}

struct Node* RLrotation(struct Node *p)
{

}

struct Node* inPre(struct Node *p)
{
    while(p&&p->lChild) p=p->lChild;
    return p;
}

struct Node* inSucc(struct Node*p)
{
    while(p&&p->rChild) p=p->rChild;
    return p;
}



int main()
{

}