#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Structure for a node in the linked list-based queue
struct QueueNode
{
    struct Node *data;
    struct QueueNode *next;
};

// Structure for the linked list-based queue
struct Queue
{
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Initialize an empty queue
void initQueue(struct Queue *q)
{
    q->front = q->rear = NULL;
}

// Check if the queue is empty
bool isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

// Enqueue a node into the queue
void enqueue(struct Queue *q, struct Node *data)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue a node from the queue
struct Node *dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return NULL;
    }
    struct QueueNode *temp = q->front;
    struct Node *data = temp->data;

    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }

    free(temp);
    return data;
}

// Create a binary tree using level order traversal
struct Node *createBinaryTree()
{
    struct Node *root = NULL;
    struct Queue q;
    initQueue(&q);

    int x;
    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        struct Node *current = dequeue(&q);

        printf("Enter left child for %d (-1 for no child): ", current->data);
        scanf("%d", &x);
        if (x != -1)
        {
            struct Node *leftChild = (struct Node *)malloc(sizeof(struct Node));
            leftChild->data = x;
            leftChild->left = leftChild->right = NULL;
            current->left = leftChild;
            enqueue(&q, leftChild);
        }

        printf("Enter right child for %d (-1 for no child): ", current->data);
        scanf("%d", &x);
        if (x != -1)
        {
            struct Node *rightChild = (struct Node *)malloc(sizeof(struct Node));
            rightChild->data = x;
            rightChild->left = rightChild->right = NULL;
            current->right = rightChild;
            enqueue(&q, rightChild);
        }
    }

    return root;
}

// Preorder traversal of the binary tree
void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

int main()
{
    struct Node *root = createBinaryTree();
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    return 0;
}
