#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
    int coeff;
    int pwr;
    struct Node *next;
};

double eval(struct Node* head, int x)
{
    double sum = 0;
    struct Node* q = head;
    while (q)
    {
        sum += q->coeff * pow(x, q->pwr);
        q = q->next;
    }
    return sum;
}

struct Node* create(struct Node* poly)
{
    struct Node *t, *last = NULL;
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp:\n");
    for (i = 0; i < num; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d %d", &t->coeff, &t->pwr);
        t->next = NULL;
        if (poly == NULL)
        {
            poly = t;
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
    return poly;
}

void display(struct Node* p)
{
    while (p)
    {
        printf("%dx^%d", p->coeff, p->pwr);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node* poly = NULL;
    poly = create(poly);
    display(poly);
    printf("%lf",eval(poly,1));
    return 0;
}
