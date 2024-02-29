#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lChild;
    int data;
    int height;
    struct Node *rChild;
}*root=NULL;


int NodeHeight(struct Node *p)
{
    int hl,hr;
    hl=(p&&p->lChild)?p->lChild->height:0;
    hr=(p&&p->rChild)?p->rChild->height:0; 
    return (hl>hr)?hl+1:hr+1;
}

int BalanceFactor(struct Node *p)
{
    int hl,hr;
    hl=(p&&p->lChild)?p->lChild->height:0;
    hr=(p&&p->rChild)?p->rChild->height:0;
    return hl-hr;
}

struct Node* LLrotation(struct Node *p)
{
    struct Node*pl=p->lChild;
    struct Node*plr=pl->rChild;

    pl->rChild=p;
    p->lChild=plr;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(p==root)
    {
        root=pl;
    }
    return pl;
}

struct Node *LRrotation(struct Node *p)
{
    struct Node *pl = p->lChild;
    struct Node *plr = pl->rChild;

    pl->rChild = plr->lChild;
    p->lChild = plr->rChild;

    plr->lChild=pl;
    plr->rChild=p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (p==root) {
        root = plr;
    }

    return plr;
}

struct Node*RRrotation(struct Node *p){return NULL;}
struct Node*RLrotation(struct Node *p){return NULL;}

struct Node *insert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; // Taking height to start from 1
        t->rChild = t->lChild = NULL;
        return t;
    }
    if (key < p->data)
        p->lChild = insert(p->lChild, key);
    else if (key > p->data)  // Corrected this line
        p->rChild = insert(p->rChild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lChild) == 1) // LL Rotation
        return LLrotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lChild) == -1)  // LR Rotation
        return LRrotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rChild) == -1)  // RR Rotation
        return RRrotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rChild) == 1)  // RL rotation
        return RLrotation(p);

    return p;
}



void inorder(struct Node*p)
{
    if(p)
    {
    inorder(p->lChild);
    printf("%d ",p->data);
    inorder(p->rChild);
    }
}


int main()
{
    root=insert(root,50);
    root=insert(root,10);
    root=insert(root,20);

    inorder(root);

    return 0;
}
