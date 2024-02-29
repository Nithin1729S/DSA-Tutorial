#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first,*temp,*last=NULL;


void create(int arr[],int n)
{
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

struct Node* LSearch(struct Node*p,int key)
{
    while(p)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}


struct Node* RSearch(struct Node*p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
}





int main(){
    struct Node *t;
    int A[]={1,2,4,5,6,77};
    int n=6;
    create(A,n);

    t=LSearch(first,4);
    if(t)
        printf("Key is found %d\n",t->data);
    else
        printf("Key is not found.");

    t=RSearch(first,77);
    if(t)
        printf("Key is found %d\n",t->data);
    else
        printf("Key is not found.");

}