// Reverse Linked list



#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void reverseList(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    
    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the prev pointer one step forward
        current = next;       // Move the current pointer one step forward
    }
    *head = prev; // Update the head to the new front of the list
}

void insert(struct node **head, int newdata) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = (*head);
    (*head) = newnode;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    insert(&head, 21);
    insert(&head, 15);
    insert(&head, 71);
    insert(&head, 1);
    
    printf("Original Linked List: ");
    printList(head);
    
    reverseList(&head);
    
    printf("\nReversed Linked List: ");
    printList(head);
    return 0;
}


/*
The approach is going to be pretty straightforward:

First, we will create three-pointers, say, prev, current and next.
Initailly prev and next will point to NULL and the current will point to the head of the list.
Now, we will traverse the list until the current is not NULL.
For every current node during list traversal, we will store the next of current in next and then make the next of current point to prev.
After that, we will make prev equal to current and current equal to next.
At last, after the traversal is over, we will make the node to which prev is pointing our new linked list head.
By performing the above operations, we are changing the links of every node and ultimately reversing the list.
*/



// Reverse Doubly Linked list

// #include <stdio.h>
// #include <stdlib.h>

// // Define the structure for a doubly linked list node
// struct node {
//     int data;
//     struct node *next;
//     struct node *prev;
// };

// // Function to reverse the doubly linked list
// void reverseList(struct node **head) {
//     struct node *temp = NULL;
//     struct node *current = *head;
    
//     // Swap next and prev for all nodes in the list
//     while (current != NULL) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }
    
//     // Before changing the head, check for the cases like empty list and list with only one node
//     if (temp != NULL) {
//         *head = temp->prev;
//     }
// }

// // Function to insert a new node at the beginning of the doubly linked list
// void insert(struct node **head, int newdata) {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     newnode->data = newdata;
//     newnode->next = (*head);
//     newnode->prev = NULL;
    
//     if ((*head) != NULL) {
//         (*head)->prev = newnode;
//     }
    
//     (*head) = newnode;
// }

// // Function to print the doubly linked list
// void printList(struct node *head) {
//     struct node *temp = head;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
// }

// int main() {
//     struct node *head = NULL;
//     insert(&head, 21);
//     insert(&head, 15);
//     insert(&head, 71);
//     insert(&head, 1);
    
//     printf("Original Linked List: ");
//     printList(head);
    
//     reverseList(&head);
    
//     printf("\nReversed Linked List: ");
//     printList(head);
//     return 0;
// }

/*
Let’s move to the algorithm section to see the above approach in depth.

Algorithm
Create a pointer current. Initialize it with the head of the linked list.
Create a pointer temp. Initialize it with NULL.
Now swap current’s prev and current’s next using pointer temp.
Now move current to current’s previous node because after swapping, current’s prev stores the address of current’s next node.
Repeat the process till current does not become NULL.

*/