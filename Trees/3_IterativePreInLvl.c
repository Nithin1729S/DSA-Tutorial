#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binaryTree.h"
//stack is made using array here!!!

struct Stack
{
    int size;
    int top;
    struct Node **S;  //stack of addresses;
};

void createStack(struct Stack *stk,int size)
{
    stk->size=size;
    stk->top=-1;
    stk->S=(struct Node*)malloc(sizeof(struct Node*));
}

void push(struct Stack *stk,struct Node*x)
{
    if(stk->top==stk->size-1) return;
    else{
        stk->top++;
        stk->S[stk->top]=x;
    }
}

struct Node* pop(struct Stack *stk)
{
    struct Node*x=NULL;
    if(stk->top==-1) return NULL;
    else
    {
        x=stk->S[stk->top];
        stk->top--;
    }
    return x;
}

int isEmptyStack(struct Stack stk)
{
    return (stk.top==-1);
}

void iterativePreorder(struct Node *p)
{
    struct Stack stk;
    createStack(&stk,100);
    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lChild;
        }
        else
        {
            p=pop(&stk);
            p=p->rChild;
        }
    }
}

void iterativeInorder(struct Node *p)
{
    struct Stack stk;
    createStack(&stk,100);
    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p=p->lChild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ",p->data); 
            p=p->rChild;
        }
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    createQueue(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if (root->lChild)
        {
            printf("%d ", root->lChild->data);
            enqueue(&q, root->lChild);
        }
        if (root->rChild)
        {
            printf("%d ", root->rChild->data);
            enqueue(&q, root->rChild);
        }
    }
}


int main()
{
    struct Node *tree1=NULL;
    createTree(&tree1); 
    printf("\nLevelorder\n");
    LevelOrder(tree1);
    return 0;
}