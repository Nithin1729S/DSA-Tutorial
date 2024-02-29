#include <stdio.h>
#include <stdbool.h>

struct DEQueue {
    int front;
    int rear;
    int size;
    int* Q;
};

void initDEQueue(struct DEQueue* dq, int size) {
    dq->size = size;
    dq->front = -1;
    dq->rear = -1;
    dq->Q = (int*)malloc(size * sizeof(int));
}

void destroyDEQueue(struct DEQueue* dq) {
    free(dq->Q);
}

bool isEmpty(struct DEQueue* dq) {
    return dq->front == dq->rear;
}

bool isFull(struct DEQueue* dq) {
    return dq->rear == dq->size - 1;
}

void enqueueFront(struct DEQueue* dq, int x) {
    if (dq->front == -1) {
        printf("DEQueue Overflow\n");
    } else {
        dq->Q[dq->front] = x;
        dq->front--;
    }
}

void enqueueRear(struct DEQueue* dq, int x) {
    if (isFull(dq)) {
        printf("DEQueue Overflow\n");
    } else {
        dq->rear++;
        dq->Q[dq->rear] = x;
    }
}

int dequeueFront(struct DEQueue* dq) {
    int x = -1;
    if (isEmpty(dq)) {
        printf("DEQueue Underflow\n");
    } else {
        x = dq->Q[dq->front];
        dq->front++;
    }
    return x;
}

int dequeueRear(struct DEQueue* dq) {
    int x = -1;
    if (dq->rear == -1) {
        printf("DEQueue Underflow\n");
    } else {
        x = dq->Q[dq->rear];
        dq->rear--;
    }
    return x;
}

void display(struct DEQueue* dq) {
    for (int i = dq->front + 1; i <= dq->rear; i++) {
        printf("%d", dq->Q[i]);
        if (i < dq->rear) {
            printf(" <- ");
        }
    }
    printf("\n");
}

int main() {

    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};

    struct DEQueue deq;
    initDEQueue(&deq, sizeof(A) / sizeof(A[0]));

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        enqueueRear(&deq, A[i]);
    }
    display(&deq);
    enqueueRear(&deq, 11);

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        dequeueFront(&deq);
    }
    dequeueFront(&deq);

    printf("\n");

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
        enqueueFront(&deq, B[i]);
    }
    display(&deq);
    enqueueFront(&deq, 10);
    enqueueFront(&deq, 12);

    for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
        dequeueRear(&deq);
    }
    display(&deq);
    dequeueRear(&deq);
    dequeueRear(&deq);

    destroyDEQueue(&deq);

    return 0;
}
