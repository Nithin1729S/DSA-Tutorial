#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
};

struct Node *stk1 = NULL;
struct Node *stk2= NULL;

void push(struct Node **head, char x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

char pop(struct Node **head)
{
    char x;
    struct Node *p = *head;
    (*head) = (*head)->next;
    x = p->data;
    free(p);
    return x;
}

int isEmpty(struct Node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

char stackTop(struct Node *head)
{
    char x = '\0';
    if (head == NULL)
        return x;
    return (head->data);
}

int outStackprecedence(char x)
{
    if (x == '\0')
        return -1;
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    else
        return -1;
}

int inStackprecedence(char x)
{
    if (x == '\0')
        return -1;
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    else
        return -1;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == ')' || x == '(')
        return 0;
    else
        return 1;
}

char *infixToPostfix(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 1));

    while (infix[i] != '\0' && infix[i] != '\n')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (outStackprecedence(infix[i]) > inStackprecedence(stackTop(stk1)))
            {
                push(&stk1, infix[i++]);
            }
            else if (outStackprecedence(infix[i]) == inStackprecedence(stackTop(stk1)))
            {
                pop(&stk1);
                i++;
            }
            else
            {
                postfix[j++] = pop(&stk1);
            }
        }
    }
    while (!isEmpty(stk1))
    {
        postfix[j++] = pop(&stk1);
    }
    postfix[j] = '\0';

    return postfix;
}

char *reverse(const char *str)
{
    int length = strlen(str);
    char *reversed = (char *)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        reversed[i] = str[length - 1 - i];
        if (reversed[i] == ')')
            reversed[i] = '(';
        else if (reversed[i] == '(')
            reversed[i] = ')';
    }
    reversed[length] = '\0';
    return reversed;
}

int eval(char *postfix)
{
    int x1;
    int x2;
    int r;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i])) push(&stk2,postfix[i]='0');
        else
        {
            x2=pop(&stk2);
            x1=pop(&stk2);
            switch(postfix[i])
            {
                case '+':
                    r=x1+x2;
                    break;
                case '-':
                    r=x1-x2;
                    break;
                case '*':
                    r=x1*x2;
                    break;
                case '/':
                    if(x2!=0) r=x1/x2;
                    else printf("Syntax Error");
                    break;
            }
            push(&stk2,r);
        }
        return pop(&stk2);
    }
}

int main()
{
    char infix[100];

    printf("Enter the infix expression: ");
    scanf("%s",infix);

    printf("Infix Expression: %s", infix);
    char *postfix = infixToPostfix(infix);
    printf("Postfix Expression: %s\n", postfix);

    char *reversedInfix = reverse(infix);
    //printf("%s",reversedInfix);
    char *reversedPostfix = reverse(infixToPostfix(reversedInfix));
    //printf("%s",reversedPostfix);
    printf("Prefix Expression: %s\n", reversedPostfix);


    return 0;
}
