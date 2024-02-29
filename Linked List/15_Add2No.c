#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node Node;

void insertLast(Node **p, int x) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (*p == NULL) {
        *p = temp;
    } else {
        Node *last = *p;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

Node *createLL(Node *p, int n) {
    while (n != 0) {
        insertLast(&p, n % 10);
        n = n / 10;
    }
    return p;
}

void print(Node *p) {
    if (p == NULL) {
        printf("No Number");
        return;
    } else {
        while (p->next != NULL) {
            printf("%d --> ", p->data);
            p = p->next;
        }
        printf("%d", p->data);
    }
}

Node* add(Node* p,Node* q)
{
    if(p->data==0)
        return p;
    if(q->data==0)
        return q;
    Node *r=p;
    Node *s=q;
    Node *res=NULL;
    int carry=0,sum=0;

    while(r||s)
    {
        sum=0;
        if(r) sum+=r->data;
        if(s) sum+=s->data;
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        insertLast(&res,sum);
        if(r) r=r->next;
        if(s) s=s->next;
    }
    if(carry)
        insertLast(&res,carry);
    return res;
}

Node* reverse(Node*p)
{
    Node* q=NULL;
    Node* r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    p=q;
    return p;
}

int main() {
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    Node *Num1 = NULL;
    Node *Num2 = NULL;
    Node *Res = NULL;

    printf("\nLinked List Representation of the number 1:\n");
    Num1 = createLL(Num1, num1);
    print(Num1);
    printf("\nLinked List Representation of the number 2:\n");
    Num2 = createLL(Num2, num2);
    print(Num2);

    printf("The Sum of two numbers:\n");
    Res=add(Num1,Num2);
    Res=reverse(Res);
    print(Res);


    return 0;
}
