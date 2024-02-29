#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertLast(struct Node **head,int x)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(*head==NULL) {*head=temp;}
    else
    {
        struct Node *p=*head;
        while(p->next) p=p->next;
        p->next=temp;
        temp->prev=p;
    }
}

void display(struct Node *head)
{
    struct Node *p=head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void reverse(struct Node **head)
{
    struct Node *temp=NULL;
    struct Node *p=*head;
    while(p)
    {
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
    }
    if(temp) *head=temp->prev;
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
    struct Node* p;
    struct Node*lptr=NULL;
    do
    {
        flg=0;
        p=head;
        while(p->next!=lptr)
        {
            if(p->data>p->next->data)
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
    if(*head==NULL || (*head)->next==NULL) return;
    struct Node *sortedList=NULL;

    while(*head!=NULL)
    {
        struct Node *curr=*head;
        (*head)=(*head)->next;

        if(sortedList==NULL || curr->data<=sortedList->data)
        {
            curr->next=sortedList;
            curr->prev=NULL;
            if(sortedList) sortedList->prev=curr;
            sortedList=curr;
        }
        else
        {
            struct Node* temp=sortedList;
            while(temp->next && temp->next->data<curr->data) temp=temp->next;
            curr->next=temp->next;
            curr->prev=temp;
            if(temp->next) temp->next->prev=curr;
            temp->next=curr;
        }

    }
    *head=sortedList;


}


void selectionSort(struct Node **head)
{
    if(*head==NULL ||(*head)->next==NULL) return;
    struct Node * curr =*head;
    while(curr)
    {
        struct Node *min=curr;
        struct Node *temp=curr->next;
        while(temp)
        {
            if(temp->data<min->data) min=temp;
            temp=temp->next;
        }
        swap(curr,min);

        curr=curr->next;
    }

}

int length(struct Node *head)
{
    int l=0;
    struct Node *p=head;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}


void insert(struct Node **head,int idx,int x)
{
    if(idx<0 || idx>(length(*head))) return ;
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    if(idx==0)
    {
        temp->prev=NULL;
        temp->next=*head;
        if(*head) (*head)->prev=temp;
        (*head)=temp;
    }
    else
    {
        struct Node *p=*head;
        for(int i=0;i<idx-1;i++) p=p->next;
        temp->next=p->next;
        temp->prev=p;
        if(p->next) p->next->prev=temp;
        p->next=temp;
    }
}

int delete(struct Node **head,int idx)
{
    if(idx<0 || idx>=(length(*head))) return -1;
    int x;
    if(idx==0)
    {
        struct Node *p=*head;
        (*head)=(*head)->next;
        x=p->data;
        free(p);
        if(*head) (*head)->prev=NULL;
    }
    else
    {
        struct Node *p=*head;
        for(int i=0;i<idx;i++) p=p->next;
        x=p->data;
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        free(p);
    }
    return x;
}

struct Node* mid(struct Node *head,struct Node *last)
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

struct Node* binarySearch(struct Node* head,int key)
{
    struct Node *start=head;
    struct Node *last=NULL;
    do
    {
        struct Node *middle=mid(start,last);
        if (middle ==NULL) return NULL;
        if(middle->data==key) return middle;
        else if(key>middle->data) start=middle->next;
        else last=middle->prev;
    } while(last==NULL || last!=start);
        return NULL;
}

int main()
{
    struct Node *LL1=NULL;
    insertLast(&LL1,5);
    insertLast(&LL1,7);
    insertLast(&LL1,12);
    insertLast(&LL1,87);
    insertLast(&LL1,3);
    selectionSort(&LL1);
    display(LL1);
    return 0;

}