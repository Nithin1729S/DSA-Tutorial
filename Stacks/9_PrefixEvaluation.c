#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *stk1 = NULL;

void push(struct Stack **head, int x)
{
    struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

int pop(struct Stack **head)
{
    int x;
    struct Stack *p = *head;
    (*head) = (*head)->next;
    x = p->data;
    free(p);
    return x;
}

int isEmpty(struct Stack *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack *head)
{
    int x = 0;
    if (head == NULL)
        return x;
    return (head->data);
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == ')' || x == '(')
        return 0;
    else
        return 1;
}


char* reverseString(const char* str)
{
    int len = strlen(str);
    char* reversed = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed;
}


int eval(char *prefixx)
{
    int x1,x2,i,r;
    char*prefix=reverseString(prefixx);
    for(i=0;prefix[i]!='\0';i++)
    {
        if(isOperand(prefix[i])) push(&stk1,prefix[i]-'0');
        else
        {
            x1=pop(&stk1);
            x2=pop(&stk1);
            switch(prefix[i])
            {
                case '+': r=x1+x2;
                          break;
                case '-': r=x1-x2; break;
                case '*': r=x1*x2;break;
                case '/': r=x1/x2;break;
            }
            push(&stk1,r);
        }
    }
    return pop(&stk1);
}

int main()
{
    char *prefix = "-+8/632";
    int res = eval(prefix);
    printf("%d ", res);
    return 0;
}