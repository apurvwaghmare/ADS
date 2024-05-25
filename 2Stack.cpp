// 2 STACK USING 1 ARRAY



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

int stack[SIZE];
int top1 = -1, top2 = SIZE;

void push1(int element1){
    if(top1 >= top2){
        printf("Stack1 Overflow\n");
    }    
    else{
        top1++;
        stack[top1] = element1;
    }
}

void push2(int element2){
    if(top2 <= top1){
        printf("Stack2 Overflow\n");
    }    
    else{
        top2--;
        stack[top2] = element2;
    }
}

int pop1(){
    if(top1 == -1){
        printf("Stack 1 Underflow\n");
        return -1;
    }
    else{
        return stack[top1--];
    }
}

int pop2(){
    if(top2 == 10){
        printf("Stack 2 Underflow\n");
        return -1;
    }
    else{
        return stack[top2++];
    }
}

void display1(){
    if(top1 == -1){
        printf("Stack1 Underflow\n");
    }
    else{
        for(int i = top1; i >= 0; i--){
            printf("%d ",stack[i]);
        }
    }
}
void display2(){
    if(top2 == 10){
        printf("Stack2 Underflow\n");
    }
    else{
        for(int i = top2; i < SIZE; i++){
            printf("%d ",stack[i]);
        }
    }
}
int main()
{
    push1(1);
    push1(2);
    push1(3);
    push1(4);
    push1(5);
    push2(10);
    push2(9);
    push2(8);
    push2(7);
    push2(6);
    pop1();
    pop1();
    pop2();
    printf("Content of Stack1 are: ");
    display1();
    printf("\nContent of Stack2 are: ");
    display2();
    return 0;
}


/*
1. take top1 = -1 and top2 = size 
2. while pushing the element in stack1 check whether top1 >= top2 if yes this means stack1 is full or else we can push into Stack1
3. while pushing the element in stack2 check whether top2 <= top1 if yes this means stack2 is full or else we can push into Stack1
4. while popping check if stack is empty or not if empty print underflow or else pop from the stack
5. for display use the logic mentioned in the code
*/