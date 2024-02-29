#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node * next;
};

void create(struct Node**head,int A[],int n)
{
    struct Node* last,*temp;
    int i;
    *head=(struct Node*)malloc(sizeof(struct Node));
    (*head)->data=A[0];
    (*head)->prev=NULL;
    (*head)->next=NULL;
    last=*head;
    for(i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next=NULL;
        temp->prev=last;
        last->next=temp;
        last=temp;
    }
}

void display(struct Node*p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct Node*p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}

void insert(struct Node** head, int idx, int x)
{
    if (idx < 0 || idx > length(*head)) return;
    
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    
    if (idx == 0)
    {
        temp->prev = NULL;
        temp->next = *head;
        
        if (*head != NULL) {
            (*head)->prev = temp;
        }
        
        *head = temp; 
    }
    else
    {
        struct Node *p = *head;
        for (int i = 0; i < idx - 1; i++) p = p->next;
        temp->next = p->next;
        temp->prev = p;
        if (p->next) p->next->prev = temp;
        p->next = temp;
    }
}

int delete(struct Node **head,int idx)
{
    int x=-1,i;
    if(idx<0||idx>length(*head)-1) return x;
    struct Node *p;
    if(idx==0)
    {
        p=*head;
        *head=(*head)->next;
        x=p->data;
        free(p);
        if(*head) (*head)->prev=NULL;
        
    }
    else
    {
        p=*head;
        for(i=0;i<idx;i++) p=p->next;
        x=p->data;
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        free(p);
    }
    return x;
}

void reverse(struct Node **head)
{
    struct Node *temp = NULL;
    struct Node *p = *head;

    while (p)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;

    }
    //temp is at 4 now....ie last second
        if (temp != NULL)
            *head = temp->prev;
}