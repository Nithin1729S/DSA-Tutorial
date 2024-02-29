#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node* top, int x) {
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack is Full");
    else {
        t->data = x;
        t->next = top->next;
        top->next = t;
    }
}

void display(struct Node* top) {
    struct Node* p;
    p = top->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int pop(struct Node* top) {
    struct Node* t;
    int x = -1;
    if (top->next == NULL)
        printf("Stack is Empty.\n");
    else {
        t = top->next;
        top->next = t->next;
        x = t->data;
        free(t);
    }
    return x;
}

int main() {
    struct Node* top = (struct Node*)malloc(sizeof(struct Node));
    top->next = NULL;
    
    push(top, 10);
    push(top, 20);
    push(top, 40);
    display(top);
    
    printf("%d ", pop(top));
    // display(top);

    free(top);
    return 0;
}
