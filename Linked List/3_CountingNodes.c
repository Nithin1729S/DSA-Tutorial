#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*temp=NULL,*last=NULL;


void create(int arr[],int n)
{
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

void count(struct Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }

    printf("%d",count);
}


int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    else 
        return Rcount(p->next)+1;
}

int add(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int main()
{
    int A[]={1,2,3,4,5};
    int n=5;
    create(A,n);
    Display(first);
    count(first);
    printf("\n%d",Rcount(first));
    printf("\nSum of all elements : %d",add(first));

    return 0;
    
}