// FACTORIAL AND FIBONACCI


#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int element){
    if(top == SIZE - 1){
        printf("Stack Overflow\n");
    } 
    else{
        top++;
        stack[top] = element;
    }
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    } 
    else{
        int element = stack[top];
        top--;
        return element;
    }
}

int factorial(){
    int fact = 1;
    for(int i = top; i >= 0; i--){
        fact *= stack[i];
    }
    return fact;
}

void fibonacci(int number){
    if(number >= 1) push(0); // 0
    if(number >= 2) push(1); // 0 1
    
    for(int i = 2; i < number; i++){
        int num1 = stack[top];
        int num2 = stack[top-1];
        push(num1 + num2);
    }
}

void display(){
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
}

int main() {
    int choice;
    printf("Enter 1 for Factorial or 2 for Fibonacci: ");
    scanf("%d", &choice);
    
    if(choice == 1){
        int n;
        printf("Enter the number: ");
        scanf("%d", &n);
        
        for(int i = 1; i <= n; i++){
            push(i);
        }
        int result = factorial();
        printf("Factorial of %d is: %d\n", n, result);
    }
    else if(choice == 2){
        int n;
        printf("Enter the number of Fibonacci terms: ");
        scanf("%d", &n);
        
        fibonacci(n);
        printf("Fibonacci series up to %d terms is: ", n);
        display();
        printf("\n");
    }
    else{
        printf("Invalid choice\n");
    }

    return 0;
}


/*
FACTORIAL-:
1. push the number from increasing order to decreasing order onto the stack until 0 is reached and go on multiplying every pushed element

FIBONACCI-:
1. if numberr of terms are >= 2 push 1 , else take the top 2 numbers from the stack and push their addition 
2. repeat the step until number of for loop terminates


INPUT
1
5

or 
2
5
*/