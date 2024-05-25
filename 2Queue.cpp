#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int queue[SIZE];
int front1 = -1, rear1 = -1;     // Front and rear for queue 1
int front2 = SIZE, rear2 = SIZE; // Front and rear for queue 2

// Enqueue operation for queue 1
void enqueue1(int element)
{
    if (rear1 + 1 == front2)
    {
        printf("Queue 1 is Full\n");
        return;
    }
    if (front1 == -1)
        front1 = 0;
    rear1 = (rear1 + 1) % SIZE;
    queue[rear1] = element;
}

// Enqueue operation for queue 2
void enqueue2(int element)
{
    if (rear2 - 1 == front1)
    {
        printf("Queue 2 is Full\n");
        return;
    }
    if (front2 == SIZE)
        front2 = SIZE - 1;
    rear2 = (rear2 - 1 + SIZE) % SIZE;
    queue[rear2] = element;
}

// Dequeue operation for queue 1
int dequeue1()
{
    if (front1 == -1)
    {
        printf("Queue 1 is Empty\n");
        return -1;
    }
    int element = queue[front1];
    if (front1 == rear1)
        front1 = rear1 = -1;
    else
        front1 = (front1 + 1) % SIZE;
    return element;
}

// Dequeue operation for queue 2
int dequeue2()
{
    if (front2 == SIZE)
    {
        printf("Queue 2 is Empty\n");
        return -1;
    }
    int element = queue[front2];
    if (front2 == rear2)
        front2 = rear2 = SIZE;
    else
        front2 = (front2 - 1 + SIZE) % SIZE;
    return element;
}

// Display both queues
void display()
{
    printf("Queue 1: ");
    if (front1 == -1)
        printf("Empty");
    else
    {
        int i = front1;
        while (i != rear1)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d", queue[i]);
    }
    printf("\n");

    printf("Queue 2: ");
    if (front2 == SIZE)
        printf("Empty");
    else
    {
        int i = front2;
        while (i != rear2)
        {
            printf("%d ", queue[i]);
            i = (i - 1 + SIZE) % SIZE;
        }
        printf("%d", queue[i]);
    }
    printf("\n");
}

int main()
{
    // Test the functions
    enqueue1(10);
    enqueue1(20);
    enqueue1(30);
    enqueue2(5);
    enqueue2(15);
    display();
    printf("Dequeuing from queue 1: %d\n", dequeue1());
    printf("Dequeuing from queue 2: %d\n", dequeue2());
    display();

    return 0;
}


/*
enqueue1 ke liye pehle vheck karo k kahi queue full to nhi  uske liye condition h rear1+1 == front2 agar true hai matlab queue1 if full
agar queue1 empty rehta hai to pehle front = 0 kro aur baadme enqueue karo, agar alreaddy elements hote hai to rear ko increment karo aur inset kro.


enqueue2 ke liye pehle vheck karo k kahi queue full to nhi  uske liye condition h rear2-1 == front1 agar true hai matlab queue2 if Full
agar queue2 empty rehta hai to pehle front2 == size kro aur baadme insert kro. agar already elements hai to rear me insert karo


dequeue1 ke liye pehle check kro k kahi queue1 empty to nhi , agar empty nhi hai to check kro k kahi ek h element to nhi agar ha to use pop kro aur front1 
ko -1 pe kro, magar 1 se jyada element rahe to front se delete kro aur front++ kro

dequeue2 ke liye pehle check kro k kahi queue2 empty to nhi , agar empty nhi hai to check kro k kahi ek h element to nhi agar ha to use pop kro aur front2 
ko SIZE pe kro, magar 1 se jyada element rahe to front se delete kro aur front-- kro

display1 ke liye pehle check kro k queue1 empty h k nhi , agar nhi to int i = front1 kro aur jab tak i != rear1 tab tak print krte raho aur i ko increment
karte raho

display2 ke liye pehle check kro k queue2 empty h k nhi , agar nhi to int i = front2 kro aur jab tak i != rear2 tab tak print krte raho aur i ko increment
karte raho
*/