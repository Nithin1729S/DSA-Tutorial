#include<stdio.h>
#include<stdlib.h>
#include "LL.h"

struct Node *Rmerge(struct Node*h1,struct Node*h2)
{
    if(h1==NULL)return h2;
    if(h2==NULL) return h1;

    if(h1->data>=h2->data)
    {
        h2->next=Rmerge(h1,h2->next);
        return h2;
    }
    else
    {
        h1->next=Rmerge(h1->next,h2);
        return h1;
    }
    return NULL;
}

struct Node* mergeKlists(struct Node**lists,int size)
{
    struct Node *res=NULL;
    if(size==0 || (size==1 && lists[0]==NULL)) return NULL;
    
    for(int i=0;i<size;i++)
    {
        res=Rmerge(res,lists[i]);
    }
    return res;
}

