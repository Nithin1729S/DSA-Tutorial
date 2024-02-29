#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lChild;
    int data;
    struct Node *rChild;
};

struct Queue
{
    int front;
    int rear;
    int size;
    struct Node** Q;
};

void createQueue(struct Queue *q,int size)
{
    q->front=-1;
    q->rear=-1;
    q->size=size;
    q->Q=(struct Node**)malloc(sizeof(struct Node**)*q->size);
}

void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
    {
        printf("Queue is Full");
        return;
    }   
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node* dequeue(struct Queue *q)
{
    struct Node *x=NULL;
    if(q->rear==q->front) return x;
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.rear==q.front;
}

void createTree(struct Node**root)
{
    struct Queue q;
    createQueue(&q,100);
    int x;
    printf("Enter the root value: ");
    scanf("%d",&x);
    *root=(struct Node*)malloc(sizeof(struct Node*));
    (*root)->data=x;
    (*root)->lChild=NULL;
    (*root)->rChild=NULL;
    enqueue(&q,*root);
    struct Node *p;
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        int n;
        printf("Enter the left child of %d or -1: ",p->data);
        scanf("%d",&n);
        if(n!=-1)
        {
            struct Node*temp=(struct Node*)malloc(sizeof(struct Node*));
            temp->data=n;
            temp->lChild=NULL;
            temp->rChild=NULL;
            p->lChild=temp;
            enqueue(&q,temp);
        }
        printf("Enter the right child of %d or -1: ",p->data);
        scanf("%d",&n);
        if(n!=-1)
        {
            struct Node*temp=(struct Node*)malloc(sizeof(struct Node*));
            temp->data=n;
            temp->lChild=NULL;
            temp->rChild=NULL;
            p->rChild=temp;
            enqueue(&q,temp);
        }
    }

}

void Preorder(struct Node *tree)
{
    if(tree)
    {
        printf("%d ",tree->data);
        Preorder(tree->lChild);
        Preorder(tree->rChild);
    }
    
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lChild);
        printf("%d ", p->data);
        Inorder(p->rChild);
    }
    
}

void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lChild);
        Postorder(p->rChild);
        printf("%d ", p->data);
    }
    
}

int count(struct Node*root)
{
    if(root)
    {
        return count(root->lChild)+count(root->rChild)+1;
    }
    return 0;
}

int height(struct Node *root)
{
    int x=0,y=0;
    if(root==NULL) return 0;
    x=height(root->lChild);
    y=height(root->rChild);
    if(x>y) return x+1;
    else return y+1;
}
int main()
{
    struct Node* tree1=NULL;
    createTree(&tree1);
    printf("Preorder: ");
    Preorder(tree1);
    printf("\nInorder: ");
    Inorder(tree1);
    printf("\nPostorder: ");
    Postorder(tree1);
    return 0;
}

