#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binaryTree.h"

struct Stack
{
    int size;
    int top;
    long int *S;
};

void createStack(struct Stack *stk,int size)
{
    stk->size=size;
    stk->top=-1;
    stk->S=(long int *)malloc(sizeof(long int));
}

void push(struct Stack *stk,long int x)
{

}

long int pop(struct Stack *stk)
{

}
