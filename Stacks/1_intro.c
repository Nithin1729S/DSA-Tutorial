#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter the Size\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
        printf("%d ",st.S[i]);
    printf("\n");
}

void push(struct Stack *st,int x)
{
    if(st->top==st->size-1)
        printf("Stack Overflow.\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
        printf("Stack Underflow.\n");
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st,int idx)
{  
    int x=-1;
    if(st.top-idx+1<0)
        printf("Invalid Index");
    x=st.S[st.top-idx+1];
    return x;
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    return st.top==st.size-1;
}

int stackTop(struct Stack st)
{
    if(!st.top==-1)
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,12);
    push(&st,11);
    push(&st,17);
    push(&st,101);
    display(st);
    //push(&st,111);
    printf("%d\n",pop(&st));
    display(st);
    printf("%d",peek(st,2));
    return 0;

}