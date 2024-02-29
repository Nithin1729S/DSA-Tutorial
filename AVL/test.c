#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* lchild;
    int data;
    struct Node* rchild;
    int height;
};

struct AVL {
    struct Node* root;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int nodeHeight(struct Node* p) {
    if (p == NULL) return 0;
    int hl = (p->lchild) ? p->lchild->height : 0;
    int hr = (p->rchild) ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(struct Node* p) {
    if (p == NULL) return 0;
    int hl = (p->lchild) ? p->lchild->height : 0;
    int hr = (p->rchild) ? p->rchild->height : 0;
    return hl - hr;
}

struct Node* LLRotation(struct Node* p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    return pl;
}

struct Node* RRRotation(struct Node* p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    return pr;
}

struct Node* LRRotation(struct Node* p) {
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);
    return plr;
}

struct Node* RLRotation(struct Node* p) {
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);
    return prl;
}

struct Node* inPre(struct Node* p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

struct Node* inSucc(struct Node* p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

struct Node* insertNode(struct Node* p, int key) {
    if (p == NULL) {
        return createNode(key);
    }

    if (key < p->data) {
        p->lchild = insertNode(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = insertNode(p->rchild, key);
    }

    p->height = nodeHeight(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }

    return p;
}

void inorder(struct Node* p) {
    if (p) {
        inorder(p->lchild);
        printf("%d, ", p->data);
        inorder(p->rchild);
    }
}

struct Node* deleteNode(struct Node* p, int key) {
    if (p == NULL) {
        return NULL;
    }

    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == p->root) {
            p->root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data) {
        p->lchild = deleteNode(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = deleteNode(p->rchild, key);
    } else {
        struct Node* q;
        if (nodeHeight(p->lchild) > nodeHeight(p->rchild)) {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = deleteNode(p->lchild, q->data);
        } else {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = deleteNode(p->rchild, q->data);
        }
    }

    p->height = nodeHeight(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0) {
        return LLRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0) {
        return RRRotation(p);
    }

    return p;
}

int main() {
    struct AVL tree;
    tree.root = NULL;

    int A[] = {10, 20, 30, 25, 28, 27, 5};
    int i;

    for (i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        tree.root = insertNode(tree.root, A[i]);
    }

    inorder(tree.root);
    printf("\n");

    tree.root = deleteNode(tree.root, 28);

    inorder(tree.root);
    printf("\n");

    return 0;
}
