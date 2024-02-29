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

struct Node* concat(struct Node*p,struct Node*q)
{
    struct Node*temp=p;
    while(p->next)
        p=p->next;
    p->next=q;
    return temp;
}

struct Node* merge(struct Node*p,struct Node*q)
{
    struct Node *last,*third;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p;last=p;p=p->next;last->next=NULL;
        }
        else
        {
            last->next=q;last=q;q=q->next;last->next=NULL;
        }
    }
    if(p) last->next=p;
    if(q) last->next=q;
    return third;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int B[] = {0, 2, 7, 4, 9, 1, 0, 12};
    int n = 8;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    create(&head1, A, n);
    create(&head2, B, n);
    display(head1);
    printf("\n");
    display(head2);
    // struct Node* concatenated=concat(head1,head2);
    // printf("\n");
    // display(concatenated);
    struct Node* merged=merge(head1,head2);
    printf("\n");
    display(merged);
    return 0;
}
