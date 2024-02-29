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

struct Node* LSearch(struct Node *p,int key)
{
    struct Node * q;
    while(p)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;

}
void DisplayLL(struct Node*p,int n)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

int main(){
    struct Node *t=NULL;
    int A[]={1,2,4,5,6,77};
    int n=6;
    create(A,n);
    DisplayLL(first,n);

    t=LSearch(first,4);
    t=LSearch(first,6);

    if(t!=NULL)
    {
        printf("Key is found\n");
    }
    else
        printf("Key is not found\n");

    DisplayLL(first,77);
    return 0;
}