#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void create(struct Node** head, int A[], int n)
{
    struct Node* last;
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->data = A[0];
    (*head)->next = NULL;
    last = *head;
    for (int i = 1; i < n; i++)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node*head)
{
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}


int isLoop(struct Node*head1)
{
    struct Node *p,*q;
    p=q=head1;
    do
    {
        p=p->next;
        q=q->next;
        if(q) q=q->next;
    }while(p&&q&&p!=q);
    if(p==q) return 1;
    else return 0;
}

int main()
{
    struct Node *head1=NULL;
    int A[]={10,20,30,40,50};
    create(&head1,A,5);
    printf("%d ",isLoop(head1));
    struct Node*t1=head1->next->next;
    struct Node*t2=head1->next->next->next->next;
    t2->next=t1;
    printf("%d ",isLoop(head1));
    
}