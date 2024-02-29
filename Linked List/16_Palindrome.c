#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode 
{
     int val;
      struct ListNode *next;
 };

void Display(struct ListNode* p)
{
    while (p != 0)
    {
        printf("%d ", p->val);
        p = p->next;
    }
}

struct ListNode* reverse(struct ListNode*head)
{
    struct ListNode* q=NULL,*r=NULL;
    struct ListNode*p=head;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
}

struct ListNode* middle(struct ListNode *head)
{
    struct ListNode*fast=head->next;
    struct ListNode*slow=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head)
{
    struct ListNode* mid=middle(head);
    Display(mid);
    printf("\n");
    struct ListNode*p=head;
    struct ListNode*q=mid->next;
    Display(q);
    printf("\n");
    mid->next=NULL;
    q=reverse(q);
    Display(q);
    printf("\n");
    while(p && q)
    {
        if(p->val!=q->val)
        {
            return false;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    return true;
}

struct ListNode* create(int A[], int n)
{
    int i;
    struct ListNode* first = NULL, * t, * last;
    first = (struct ListNode*)malloc(sizeof(struct ListNode));
    first->val = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct ListNode*)malloc(sizeof(struct ListNode));
        t->val = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return first;
}


int main()
{
    struct ListNode* first = NULL;
    int A[] = {1,1,2,1}; // Change to a palindrome list
    first = create(A, 4);
    Display(first);
    printf("\n");
    if (isPalindrome(first)==true)
    {
        printf("The list is a palindrome.\n");
    }
    else
    {
        printf("The list is not a palindrome.\n");
    }

    return 0;
}