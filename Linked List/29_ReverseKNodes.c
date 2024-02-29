#include<stdio.h>
#include<stdlib.h>
#include "LL.h"


struct Node*reverseKnodes(struct Node *head,int k)
{   
    struct Node *kth=head;
    for(int i=0;i<k;i++)
    {
        if(kth==NULL) return NULL;
        kth=kth->next;
    }

    struct Node*curr=head;
    struct Node*prev=NULL;
    struct Node*temp=NULL;
    int count=0;
    while(count<k && curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        count++;
    }
    if(temp!=NULL) head->next=reverseKnodes(temp,k);
    return prev;

}

int main()
{
    struct Node *LL1=NULL;
    insertLast(&LL1,1);
    insertLast(&LL1,2);
    insertLast(&LL1,3);
    insertLast(&LL1,4);
    LL1=reverseKnodes(LL1,2);
    display(LL1);
}