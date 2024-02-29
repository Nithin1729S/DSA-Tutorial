#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*first=NULL;



void createLL(int A[],int size)
{
    int i;
    struct Node *temp,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<size;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
    
}



void RDisplayLL(struct Node *p)
{
    if(p)
    {
        printf("%d\n",p->data);
        RDisplayLL(p->next);
    }
}

void RRDisplayLL(struct Node *p)
{
    if(p)
    {
        RDisplayLL(p->next);
        printf("%d\n",p->data);
        
    }
}



void Display(struct Node *p)
{
    while(p)
    {
        printf("%d",p->data);
        p=p->next;
    }
}


int main()
{
    int A[]={1,3,4,5,6};
    createLL(A,5);
    RDisplayLL(first);
    RRDisplayLL(first);
    return 0;

}




