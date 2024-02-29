#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    char data;
    struct Node *next;
}*top = NULL;

void push(char x)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack is Full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node *t;
    char x = -1;
    if (top == NULL)
        printf("Stack is Empty.\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p = top;
    while (p)
    {
        printf("%c ", p->data);
        p = p->next;
    }
}

int isBalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == NULL)
                return 0;
            char popped = pop();
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == ']' && popped != '[') ||
                (exp[i] == '}' && popped != '{'))
                return 0;
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "((x+b)+[y+z])";
    printf("%d\n", isBalanced(exp));
    return 0;
}
