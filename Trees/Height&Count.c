#include<stdio.h>
#include<stdlib.h>
#include"binaryTree.h"


int count(struct Node*root)
{
    if(root)
    {
        return count(root->lChild)+count(root->rChild)+1;
    }
    return 0;
}

int height(struct Node *root)
{
    int x=0,y=0;
    if(root==NULL) return 0;
    x=height(root->lChild);
    y=height(root->rChild);
    if(x>y) return x+1;
    else return y+1;
}

int main()
{
    struct Node* tree1=NULL;
    createTree(&tree1);
    printf("Preorder: ");
    Preorder(tree1);
    printf("Count: %d",count(tree1));
    printf("Height: %d",height(tree1));
    return 0;
}