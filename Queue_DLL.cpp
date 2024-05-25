// Queue DLL

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

struct queue *createqueue()
{
    struct queue *newqueue = (struct queue *)malloc(sizeof(struct queue));
    newqueue->front = NULL;
    newqueue->rear = NULL;
    return newqueue;
}

void enqueue(struct queue *q, int data)
{
    struct node *newnode = createnode(data);
    if (q->rear == NULL)
    { 
        q->front = newnode;
        q->rear = newnode;
    }
    else
    {
        q->rear->next = newnode;
        newnode->prev = q->rear;
        q->rear = newnode;
    }
    // printf("Enqueued %d\n", data);
}

int dequeue(struct queue *q)
{
    if (q->front == NULL)
    { 
        printf("Queue Underflow\n");
        return -1;
    }
    struct node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front != NULL)
    {
        q->front->prev = NULL;
    }
    else
    {
        q->rear = NULL; 
    }
    // printf("Dequeued %d\n", data);
    return data;
}

int isEmpty(struct queue *q)
{
    return q->front == NULL;
}

void printqueue(struct queue *q)
{
    struct node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct queue *q = createqueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue after enqueue operation: ");
    printqueue(q);

    dequeue(q);
    dequeue(q);

    printf("Queue after dequeue operation: ");
    printqueue(q);

    return 0;
}

/*

Enqueue (ADD) Operation:

Create a new node.
Check if the queue is empty.
If empty, set the new node as both the front and rear of the queue.
If not empty, link the new node to the rear and update the rear pointer.

Dequeue (DELETE) Operation:

Check if the queue is empty.
Store the current front node.
Retrieve the data.
Update the front pointer.
Update the new front node's prev pointer.
If the queue becomes empty, update the rear pointer.
Free the memory of the removed node.
Return the data of the removed node.
*/