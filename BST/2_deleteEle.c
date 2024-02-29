#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node*lChild;
    int data;
    struct Node *rChild;
};

struct Node *insert(struct Node *root,int key)
{
    struct Node *temp=NULL;
    if(root==NULL)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=key;
        temp->rChild=NULL;
        temp->lChild=NULL;
        return temp;
    }
    if(key<root->data) root->lChild=insert(root->lChild,key);
    else if (key>root->data) root->rChild=insert(root->rChild,key);
    return root;
}

void Inorder(struct Node*p)
{
    if(p)
    {
        Inorder(p->lChild);
        printf("%d ",p->data);
        Inorder(p->rChild);
    }
}

int height(struct Node* root)
{
    int x=0,y=0;
    if(root==NULL) return 0;
    x=height(root->lChild);
    y=height(root->rChild);
    if(x>y) return x+1;
    else return y+1;
}

struct Node* InPre(struct Node*p )
{
    while(p && p->rChild!=NULL)
        p=p->rChild;
    return p;
}

struct Node *InSucc(struct Node*p)
{
    while(p && p->lChild!=NULL)
    {
        p=p->lChild;
    }
    return p;
}

struct Node* delete(struct Node*root,int key)
{
    struct Node* q=NULL;
    if(root==NULL) return NULL;
    if(root->lChild==NULL && root->rChild==NULL) // ie a leaf node
    {
        free(root);
        return NULL;
    }
    if(key<root->data) root->lChild=delete(root->lChild,key);
    else if(key>root->data) root->rChild=delete(root->rChild,key);
    else
    {
        if(height(root->lChild)>height(root->rChild))
        {
            q=InPre(root->lChild);
            root->data=q->data;
            root->lChild=delete(root->lChild,q->data);
        }
        else
        {
            q=InSucc(root->rChild);
            root->data=q->data;
            root->rChild=delete(root->rChild,q->data);
        }
    }
    return root;

}

int main()
{
    struct Node *bst1=NULL;

    bst1=insert(bst1,5);
    bst1=insert(bst1,3);
    bst1=insert(bst1,2);
    bst1=insert(bst1,6);
    bst1=insert(bst1,4);
    bst1=insert(bst1,7);
    //Before deleting a node check whether it is present in the BST ..and then delete it...
    //bst1=delete(bst1,100);
    //bst1=delete(bst1,1);

    Inorder(bst1);
    return 0;
}