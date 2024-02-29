#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void createLL(int arr[],int n)
{
    struct Node *last,*temp;
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

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

int count(struct Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;


}

int delete(struct Node *p,int idx)
{
    struct Node *q=NULL;
    int x=-1;
    if(idx<1|| idx>count(p))
        return -1;
    
    if(idx==1)
    {
        q=p;
        x=p->data;
        p=p->next;
        free(q);
        return x;
    }

    else
    {
        for(int i=0;i<idx-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;  //p removed from the LL
        x=p->data;
        free(p);
        return x;


    }

    
    
}

int main()
{
    int A[]={1,21,3,4};
    int n=4;
    createLL(A,n);
    Display(first);
    printf("\n");
    printf("%d",delete(first,1));
    printf("\n");
    Display(first);
    return 0;
}



    