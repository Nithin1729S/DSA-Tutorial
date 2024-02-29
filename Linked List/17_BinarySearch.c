#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertLast(struct Node**head,int x)
{
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); 
    }
    temp->data=x;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        struct Node *p;
        p=*head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

struct Node* middle(struct Node* start,struct  Node* last)   //this gives first most node if the number of elements are even
{
    if (start == NULL)
        return NULL;

    struct Node* slow = start;
    struct Node* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

struct Node* binarySearch(struct Node* head, int value)
{
    struct Node* start = head;
    struct Node* last = NULL;

    do {
        
        struct Node* mid = middle(start, last);

        if (mid == NULL)
            return NULL;

       
        if (mid->data == value)
            return mid;

        
        else if (mid->data < value)
            start = mid->next;

        else
            last = mid;

    } while (last == NULL || last != start);

    return NULL;
}

int main()
{
    struct Node *ll1=NULL;
    insertLast(&ll1,2);
    insertLast(&ll1,3);
    insertLast(&ll1,5);
    insertLast(&ll1,7);
    insertLast(&ll1,9);
    insertLast(&ll1,10);
    display(ll1);
    printf("%d ",middle(ll1,NULL)->data);
    if (binarySearch(ll1, 10) == NULL)
        printf("Value not present\n");
    else
        printf("Present");
    return 0;
}