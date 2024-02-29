#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertLast(struct Node**head,int x)
{
    struct Node *p=*head;
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(p==NULL)
    {
        *head=temp;
    }
    else
    {
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
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

void insertionSort(struct Node **head)
{
    
}
int main()
{
    struct Node* head1=NULL;
    insertLast(&head1,4);
    insertLast(&head1,0);
    insertLast(&head1,8);
    display(head1);
    return 0;

}
