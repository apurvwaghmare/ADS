#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1 && rear == -1);
}

int isFull()
{
    return ((rear + 1) % SIZE == front);
}

void addfront(int x)
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else if (isEmpty())
    {
        front = rear = 0;
        queue[front] = x;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
        queue[front] = x;
    }
    else
    {
        front--;
        queue[front] = x;
    }
}

void addrear(int x)
{
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else if (isEmpty())
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queue[rear] = x;
    }
}

void removefront()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        printf("Removed %d from front\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Removed %d from front\n", queue[front]);
        front = (front + 1) % SIZE;
    }
}

void removerear()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        printf("Removed %d from rear\n", queue[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Removed %d from rear\n", queue[rear]);
        rear = SIZE - 1;
    }
    else
    {
        printf("Removed %d from rear\n", queue[rear]);
        rear--;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i = front;
        printf("Queue elements: ");
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        printf("\n");
    }
}

int main()
{
    addfront(10);
    addrear(20);
    addfront(30);
    display(); // Output: 30 10 20
    removefront();
    removerear();
    display(); // Output: 10
    return 0;
}

/*
The logic of each function in the circular double-ended queue implementation is as follows:

addfront(int x):

Check if the queue is full. If it is, print a message indicating that the queue is full.
If the queue is empty, set both the front and rear pointers to 0 and insert the element at the front.
If the front pointer is at the beginning of the array (index 0), wrap it around to the end of the array (index SIZE - 1) and insert the element.
Otherwise, decrement the front pointer and insert the element.
addrear(int x):

Check if the queue is full. If it is, print a message indicating that the queue is full.
If the queue is empty, set both the front and rear pointers to 0 and insert the element at the rear.
Increment the rear pointer (circularly) and insert the element at the new rear position.
removefront():

Check if the queue is empty. If it is, print a message indicating that the queue is empty.
If there's only one element in the queue (front == rear), remove it and set both front and rear pointers to -1 (indicating an empty queue).
Otherwise, increment the front pointer (circularly) to remove the front element.
removerear():

Check if the queue is empty. If it is, print a message indicating that the queue is empty.
If there's only one element in the queue (front == rear), remove it and set both front and rear pointers to -1 (indicating an empty queue).
If the rear pointer is at the beginning of the array (index 0), wrap it around to the end of the array (index SIZE - 1) to remove the element.
Otherwise, decrement the rear pointer to remove the element.
*/