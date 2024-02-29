#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int length(struct Node*head)
{
    struct Node *p=head;
    if(p==NULL) return 0;
    else return (length(p->next))+1;
}

struct Node* middle(struct Node *head)
{
    struct Node*fast=head->next;
    struct Node *slow=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

struct Node *mid(struct Node *head,struct Node* last)
{
    if(head==NULL) return NULL;
    struct Node *fast=head->next;
    struct Node *slow=head;
    while(fast!=last && fast->next!=last)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct Node* binarySearch(struct Node *head,int val)
{
    struct Node *start=head;
    struct Node *last=NULL;
    do 
    {
        struct Node *middle=mid(start,last);
        if(middle==NULL) return NULL;
        if(middle->data==val) return middle;
        else if(middle->data>val) last=middle;
        else start=middle->next;

    }while(last!=start || last==NULL);
    return NULL;
}

void reverse(struct Node **head)
{
    struct Node *p=*head;
    struct Node *q=NULL;
    struct Node *r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *head=q;
}


void display(struct Node *head)
{
    struct Node *p=head;
    if(p)
    {
        printf("%d ",p->data);
        display(p->next);
    }
}

void insertLast(struct Node **head,int x)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;

    }
    else
    {
        struct Node *p=*head;
        while(p->next) p=p->next;
        p->next=temp;

    }

}

void insert(struct Node **head,int idx,int x)
{
    if(idx<0 || idx>length(*head)) return ;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;

    if(idx==0)
    {
        temp->next=*head;
        *head=temp;
    }
    else
    {
        struct Node *p=*head;
        for(int i=0;i<idx-1;i++) p=p->next;
        temp->next=p->next;
        p->next=temp;

    }
}

int delete(struct Node **head,int idx)
{
    int x=-1;
    if(idx<0 || idx>=length(*head)) return x;
    if(idx==0)
    {
        struct Node*p=*head;
        (*head)=(*head)->next;
        x=p->data;
        free(p);
    }
    else
    {
        struct Node*p=*head;
        struct Node *prev=NULL;
        for(int i=0;i<idx;i++)
        {
            prev=p;
            p=p->next;
        }
        prev->next=p->next;
        x=p->data;
        free(p);
    }
    return x;
}

void swap(struct Node *a,struct Node *b)
{
    int temp=a->data;
    a->data=b->data;
    b->data=temp;

}

void bubbleSort(struct Node *head)
{
    int flg;
    struct Node *p;
    struct Node *lptr=NULL;
    do
    {
        flg=0;
        p=head;
        while(p->next!=lptr)
        {
            if(p->data > p->next->data)
            {
                swap(p,p->next); 
                flg=1;
            }
            p=p->next;
        }
        lptr=p;
    } while (flg);
}


void insertionSort(struct Node **head)
{
    if(*head==NULL || (*head)->next==NULL) return ;
    struct Node *sortedList=NULL;
    while(*head!=NULL)
    {
        struct Node *curr=*head;
        (*head)=(*head)->next;
        if(sortedList==NULL || curr->data<sortedList->data)
        {
            curr->next=sortedList;
            sortedList=curr;
        }
        else
        {
            struct Node *temp=sortedList;
            while(temp->next && temp->next->data<curr->data)
            {
                temp=temp->next;
            }
            curr->next=temp->next;
            temp->next=curr;
        }
        
    }
    *head=sortedList;
}

void selectionSort(struct Node** head)
{
    if (*head == NULL || (*head)->next == NULL)  return;

    struct Node* curr = *head;

    while (curr != NULL) 
    {
        struct Node* min = curr;
        struct Node* temp = curr->next;

        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }
        
        swap(curr, min); 
        curr = curr->next;
    }
}

int main()
{
    struct Node *LL1=NULL;
    int A[]={1,4,5,3,2,78,12,34};
    for(int i=0;i<7;i++)
    {
        insert(&LL1,i,A[i]);
    }
    selectionSort(&LL1);
    display(LL1);
    return 0;
    



}