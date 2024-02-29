#include<stdio.h>
#include<stdlib.h>
#include "LL.h"

 
struct Node*merge(struct Node*p,struct Node*q)
{
    struct Node *last,*third;
    if(p->data <q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        } 

    }
    if(p) last->next=p;
    if(q) last->next=q;
    return third;
}


struct Node*Rmerge(struct Node*h1,struct Node*h2)
{
    if(h1==NULL) return h2;
    if(h2==NULL) return h1;
    
    if(h2->data<h1->data)
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

struct Node*mergeSort(struct Node*head)
{
    if(!head || !head->next) return head;
    struct Node*fast=head;
    struct Node*slow=head;
    struct Node*tail=head;

    while(fast && fast->next)
    {
        fast=fast->next->next;
        tail=slow;
        slow=slow->next;
    }

    tail->next=NULL;

    struct Node*h1=mergeSort(head);
    struct Node*h2=mergeSort(slow);

    return Rmerge(h1,h2);
}


int main()
{
    struct Node*LL1=NULL;
    insertLast(&LL1,10);
    insertLast(&LL1,14);
    insertLast(&LL1,2);
    insertLast(&LL1,98);
    insertLast(&LL1,78);
    LL1=mergeSort(LL1);
    display(LL1);
    return 0;
}

