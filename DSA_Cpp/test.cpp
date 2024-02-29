#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(Node* p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insertLast(Node** head, int val)
{
    Node* p = *head;
    Node* temp = new Node(val);
    if (p == NULL)
    {
        *head = temp;
        return;
    }
    while (p->next)
    {
        p = p->next;
    }
    p->next = temp;
}

Node* Reverse(Node* head, Node* q)
{
    Node* p = head;
    if (p)
    {
        Reverse(p->next, p);
        p->next = q;
    }
    else
    {
        head = q;
    }
    return head;
}

int main()
{
    Node* LL1 = NULL;
    insertLast(&LL1, 10);
    insertLast(&LL1, 11);
    insertLast(&LL1, 12);

    LL1 = Reverse(LL1, NULL);
    display(LL1);

    return 0;
}
