// DLL ALL OPERATIONS




#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = (*head);
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

void deleteAfter(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("Node to be deleted is NULL or the next node is NULL.\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = prevNode;
    }
    free(temp);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtStart(&head, 0);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);

    printList(head);

    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteAfter(head->next); // Deleting after the second node

    printList(head);

    return 0;
}


/*

insertAtStart: This function inserts a new node with the given data at the beginning of the doubly linked list.
It allocates memory for the new node, sets its data, sets its next pointer to the current head of the list, and
updates the previous pointer of the current head to point to the new node. Finally, it updates the head pointer
to point to the new node.

insertAtEnd: This function inserts a new node with the given data at the end of the doubly linked list. 
It allocates memory for the new node, traverses the list to find the last node, updates the next pointer
of the last node to point to the new node, sets the previous pointer of the new node to point to the last node, 
and sets the next pointer of the new node to NULL if it's the last node.

insertAfter: This function inserts a new node with the given data after a specified node. 
It allocates memory for the new node, sets its data, sets its next pointer to the next node of the specified node,
updates the next pointer of the specified node to point to the new node, sets the previous pointer of the new node to point to the specified node,
and updates the previous pointer of the next node to point to the new node if it exists.

deleteFromBeginning: This function deletes the first node of the doubly linked list. It checks if the list is empty, 
then it updates the head pointer to point to the next node (if it exists), updates the previous pointer of the new head to NULL, 
and frees the memory of the deleted node.

deleteFromEnd: This function deletes the last node of the doubly linked list. It checks if the list is empty, 
then it traverses the list to find the last node, updates the next pointer of the second last node to NULL, 
updates the head pointer to NULL if the list contains only one node, and frees the memory of the deleted node.

deleteAfter: This function deletes the node following a specified node. It checks if the specified node or the next node is NULL,
then it updates the next pointer of the specified node to skip the next node, updates the previous pointer of the node after the deleted node
(if it exists), and frees the memory of the deleted node.
*/