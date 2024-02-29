#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(struct Node* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element in the queue
void enqueue(struct Queue* queue, struct Node* data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
struct Node* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL; // Queue is empty
    }
    struct Node* frontNode = queue->front;
    queue->front = frontNode->next;
    if (queue->front == NULL) {
        queue->rear = NULL; // If the last element is dequeued
    }
    return frontNode;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to print the elements in the queue
void printQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the queue
void freeQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        free(dequeue(queue));
    }
    free(queue);
}

int main() {
    struct Queue* queue = createQueue();

    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));

    node1->data = NULL;
    node2->data = NULL;

    enqueue(queue, node1);
    enqueue(queue, node2);

    printf("Queue: ");
    printQueue(queue);

    struct Node* dequeuedNode = dequeue(queue);
    printf("Dequeued Node: %p\n", dequeuedNode->data);
    free(dequeuedNode);

    printf("Queue after dequeue: ");
    printQueue(queue);

    freeQueue(queue);

    return 0;
}
