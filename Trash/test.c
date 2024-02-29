#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    char data;
    struct Stack *next;
};

struct Stack *stk1=NULL;
struct Stack *stk2=NULL;

void push(struct Stack **head,char c)
{
    struct Stack *temp=(struct Stack *)malloc(sizeof(struct Stack));
    temp->data=c;
    temp->next=*head;
    *head=temp;
}

char pop(struct Stack **head)
{
    char c;
    if(*head==NULL) return '\0';
    struct Stack *p=*head;
    (*head)=(*head)->next;
    c=p->data;
    free(p);
    return c;
}

int isEmpty(struct Stack *head)
{
    return (head==NULL)?1:0;
}

char stackTop(struct Stack*head)
{
    if(head==NULL) return '\0';
    return (head->data);
}

int outStackPre(char x)
{
    if(x=='\0') return -1;
    if(x=='+' || x=='-') return 1;
    if(x=='*'|| x=='/') return 3;
    if(x=='^') return 6;
    if(x=='(') return 7;
    if(x==')') return 0;
    else return -1;
}

int inStackPre(char x)
{
    if(x=='\0') return -1;
    if(x=='+' || x=='-') return 2;
    if(x=='*'|| x=='/') return 4;
    if(x=='^') return 5;
    if(x=='(') return 0;
    else return -1;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == ')' || x == '(') return 0;
    else return 1;
}

char* infixToPostfix(char*infix)
{
    int length=strlen(infix);
    char *postfix=(char*)malloc(sizeof(char)*(length+1));
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i])) postfix[j++]=infix[i++];
        else
        {
            if(outStackPre(infix[i])>inStackPre(stackTop(stk1))) push(&stk1,infix[i++]);
            else if(outStackPre(infix[i])==inStackPre(stackTop(stk1)))
            {
                pop(&stk1);
                i++;
            }
            else postfix[j++]=pop(&stk1);
        }

    }
    while(!isEmpty(stk1))
    {
        postfix[j++]=pop(&stk1);
    }
    postfix[j]='\0';
    return postfix;
}

char* reverseString(const char* str) {
    int length = strlen(str);
    char* reversed = (char*)malloc((length + 1) * sizeof(char)); 

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
        if(reversed[i]==')') reversed[i]='(';
        else if(reversed[i]=='(') reversed[i]=')';
    }
    reversed[length] = '\0'; 
    return reversed;
}


int main()
{
    char infix1[] = "A-B/(C*D^E)";
    char *infix2=reverseString(infix1);
    char *postfix = infixToPostfix(infix1);
    char *prefix = reverseString(infixToPostfix(infix2));
    printf("Infix: %s\n", infix1);
    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);
    free(postfix);
    free(prefix);

    return 0;
}