#include <stdio.h>
#include <stdlib.h>

struct TBTnode {
    int data;
    int lbit;
    int rbit;
    struct TBTnode *left;
    struct TBTnode *right;
};

struct QueueNode {
    struct TBTnode *data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct TBTnode *createnode(struct TBTnode *head, int key) {
    struct TBTnode *newnode = (struct TBTnode *)malloc(sizeof(struct TBTnode));
    newnode->data = key;
    newnode->lbit = 0;
    newnode->rbit = 0;

    if (head->left == head) {
        newnode->left = head->left;
        head->left = newnode;
        newnode->right = head;
        head->lbit = 1;
    } else {
        struct TBTnode *temp = head->left;
        while (1) {
            if (key < temp->data) {
                if (temp->lbit == 0) {
                    newnode->left = temp->left;
                    temp->left = newnode;
                    newnode->right = temp;
                    temp->lbit = 1;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->rbit == 0) {
                    newnode->right = temp->right;
                    temp->right = newnode;
                    newnode->left = temp;
                    temp->rbit = 1;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    return head;
}

void preorder(struct TBTnode *head) {
    struct TBTnode *temp = head->left;
    while (temp != head) {
        printf("%d ", temp->data);
        if (temp->lbit == 1) {
            temp = temp->left;
        } else {
            while (temp->rbit == 0) {
                temp = temp->right;
            }
            temp = temp->right;
        }
    }
}

void inorder(struct TBTnode *head) {
    struct TBTnode *temp = head->left;
    while (temp != head) {
        while (temp->lbit == 1) {
            temp = temp->left;
        }
        printf("%d ", temp->data);
        while (temp->rbit == 0 || temp->right == head) {
            if (temp->right == head) return;
            temp = temp->right;
            printf("%d ", temp->data);
        }
        temp = temp->right;
    }
}

// Enqueue a node to the queue
void enqueue(struct Queue *q, struct TBTnode *node) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = node;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue a node from the queue
struct TBTnode *dequeue(struct Queue *q) {
    if (q->front == NULL)
        return NULL;

    struct TBTnode *temp = q->front->data;
    struct QueueNode *tempNode = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(tempNode);
    return temp;
}

// Level order traversal
void levelOrder(struct TBTnode *head) {
    if (head == NULL)
        return;

    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;

    struct TBTnode *temp = head->left;
    enqueue(q, temp);

    while (q->front != NULL) {
        temp = dequeue(q);
        printf("%d ", temp->data);

        if (temp->lbit == 1)
            enqueue(q, temp->left);
        if (temp->rbit == 1)
            enqueue(q, temp->right);
    }

    free(q);
}

int main() {
    struct TBTnode *root = NULL;
    struct TBTnode *head = NULL;

    head = (struct TBTnode *)malloc(sizeof(struct TBTnode));
    head->lbit = 0;
    head->rbit = 1;
    head->left = head;
    head->right = head;

    root = createnode(head, 50);
    root = createnode(head, 20);
    root = createnode(head, 30);
    root = createnode(head, 60);
    root = createnode(head, 25);
    root = createnode(head, 40);
    root = createnode(head, 65);
    root = createnode(head, 80);
    root = createnode(head, 70);
    root = createnode(head, 22);
    root = createnode(head, 28);
    root = createnode(head, 45);

    printf("Preorder Traversal: ");
    preorder(head);
    printf("\n");
    printf("Inorder Traversal: ");
    inorder(head);
    printf("\n");
    printf("Level Order Traversal: ");
    levelOrder(head);
    printf("\n");

    return 0;
}

/*
Insertion Logic:

Checks if the tree is empty. If so, the new node becomes the left child of the head node, and the head node's left and right pointers are adjusted to form a circular link.
If the tree is not empty, it traverses the tree to find the appropriate position to insert the new node based on its key value.
It compares the key value of the new node with each node's key value while traversing.
If the key is less than the current node's key, it moves to the left child.
If the left child is not a thread (lbit == 0), it continues traversing to the left.
If the left child is a thread (lbit == 1), it inserts the new node as the left child of the current node and adjusts the threads.
If the key is greater than or equal to the current node's key, it moves to the right child.
If the right child is not a thread (rbit == 0), it continues traversing to the right.
If the right child is a thread (rbit == 1), it inserts the new node as the right child of the current node and adjusts the threads.
*/