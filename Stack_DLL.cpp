// STACK Push and pop
// Using DLL


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct stack{
    struct node *top;    
};

struct node *createnode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> prev = NULL;
    newnode -> next = NULL;
    return newnode;
}

struct stack *createstack(){
    struct stack *newstack = (struct stack *)malloc(sizeof(struct stack));
    newstack -> top = NULL;
    return newstack;
}

void push(struct stack *newstack, int data){
    struct node *newnode = createnode(data);
    if(newstack -> top == NULL){
        newstack -> top = newnode;
    }
    else{
        newnode -> next = newstack -> top;
        newstack -> top -> prev = newnode;
        newstack -> top = newnode;
    }
    //printf("Pushed %d onto the stack\n", data);
}

int pop(struct stack *newstack){
    if(newstack -> top == NULL){
        printf("Stack Undeflow\n");
        return -1;
    }    
    struct node *temp = newstack -> top;
    int element = temp -> data;
    newstack -> top = newstack -> top -> next;
    if(newstack -> top != NULL){
        newstack -> top -> prev = NULL;
    }
    //printf("Popped %d from the stack\n", element);
    return element;
    printf("\n");
}

int emptystack(struct stack *newstack){
    return newstack -> top == NULL;
}

void printstack(struct stack *newstack){
    struct node *temp = newstack -> top;
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main()
{
    struct stack *s = createstack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    printf("After pushing: ");
    printstack(s);
    
    pop(s);
    pop(s);
    printf("After popping: ");
    printstack(s);
    
    return 0;
}

/* 

PUSH LOGIC

void push(struct stack *newstack, int data){
    struct node *newnode = createnode(data); // Step 1: Create a new node with the given data
    if(newstack->top == NULL){ // Step 2: Check if the stack is empty
        newstack->top = newnode; // If empty, the new node is the top node
    } else {
        newnode->next = newstack->top; // Step 3: Link the new node to the current top node
        newstack->top->prev = newnode; // Step 4: Link the current top node back to the new node
        newstack->top = newnode; // Step 5: Update the top pointer to the new node
    }
}


POP LOGIC 

int pop(struct stack *newstack){
    if(newstack->top == NULL){ // Step 1: Check if the stack is empty
        printf("Stack Underflow\n"); // If empty, print an error message
        return -1; // Return an error code
    }
    struct node *temp = newstack->top; // Step 2: Store the current top node in a temporary variable
    int element = temp->data; // Step 3: Get the data from the top node
    newstack->top = newstack->top->next; // Step 4: Update the top pointer to the next node
    if(newstack->top != NULL){ // Step 5: Check if the stack is not empty after the update
        newstack->top->prev = NULL; // If not empty, set the prev pointer of the new top node to NULL
    }
    free(temp); // Step 6: Free the memory of the removed node
    return element; // Step 7: Return the data of the removed node
}

*/
