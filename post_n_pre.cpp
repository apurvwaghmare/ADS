// INFIX TO POSTFIX
// INFIX TO PREFIX


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

int emptystack(){
    return top == -1;
}

int isfull(){
    return top == MAX-1;    
}

void push(char c){
    if(!isfull()){
        stack[++top] = c;
    }    
    else{
        printf("Stack Overflow\n");
    }
}

char pop() {
    if(!emptystack()){
        return stack[top--];
    }
    else{
        printf("Stack Undeflow\n");
        return '\0';
    }
}

char peek(){
    if(!emptystack()){
        return stack[top];
    }    
    else{
        return '\0';
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';   
}

void infixTOpostfix(char s[]){
    char postfix[100];
    int k = 0;
    
    for(int i = 0; s[i] != '\0'; i++){
        char c = s[i];
        
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            postfix[k++] = s[i];
        }
        else if(c == '('){
            push(s[i]);
        }
        else if(s[i] == ')'){
            while(!emptystack() && peek() != '('){
                postfix[k++] = pop();
            }
            pop();
        }
        else if(isOperator(s[i])){
            while(!emptystack() && precedence(peek()) >= precedence(s[i])){
                postfix[k++] = pop();
            }
            push(s[i]);
        }
    }
    while(!emptystack()){
        postfix[k++] = pop();
    }
    
    printf("the Postfix expression is: %s",postfix);
    
}

int main()
{
    char str[] = "A*(B+C)/D-G";
    infixTOpostfix(str);
    return 0;
}

/* Algorithm to convert the infix expression to postfix expression
1. Scan the infix expression from left to right
2. if character is an operan print that character
3. if character is an openig bracket '(' then push it into the stack
4. if character is an closing bracket ')'  then opp and print all the characters until '(' is found, the pop '('
5. if character is an operator then check its precedency 
   a. if precedency of character of top of the stack is greater than or equal to precedency of charater coming then
       pop the operator and print it and push the incoming character.
6. at the end pop everything frrom the stack
*/


// INFIX TO PREFIX 


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 100

// char stack[MAX];
// int top = -1;

// int emptystack() {
//     return top == -1;
// }

// int isfull() {
//     return top == MAX - 1;
// }

// void push(char c) {
//     if (!isfull()) {
//         stack[++top] = c;
//     } else {
//         printf("Stack Overflow\n");
//     }
// }

// char pop() {
//     if (!emptystack()) {
//         return stack[top--];
//     } else {
//         printf("Stack Underflow\n");
//         return '\0';
//     }
// }

// char peek() {
//     if (!emptystack()) {
//         return stack[top];
//     } else {
//         return '\0';
//     }
// }

// int precedence(char op) {
//     switch (op) {
//         case '+':
//         case '-':
//             return 1;
//         case '*':
//         case '/':
//             return 2;
//         case '^':
//             return 3;
//         default:
//             return 0;
//     }
// }

// int isOperator(char c) {
//     return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
// }

// void reverseString(char *str) {
//     int length = strlen(str);
//     for (int i = 0; i < length / 2; i++) {
//         char temp = str[i];
//         str[i] = str[length - i - 1];
//         str[length - i - 1] = temp;
//     }
// }

// void infixTOprefix(char s[]) {
//     char prefix[MAX];
//     int k = 0;
//     int len = strlen(s);
//     for (int i = 0; s[i] != '\0'; i++) {
//         char c = s[i];

//         if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
//             prefix[k++] = s[i];
//         } else if (c == '(') {
//             push(s[i]);
//         } else if (s[i] == ')') {
//             while (!emptystack() && peek() != '(') {
//                 prefix[k++] = pop();
//             }
//             pop(); // Pop '('
//         } else if (isOperator(s[i])) {
//             while (!emptystack() && precedence(peek()) >= precedence(s[i])) {
//                 prefix[k++] = pop();
//             }
//             push(s[i]);
//         }
//     }
//     while (!emptystack()) {
//         prefix[k++] = pop();
//     }
//     reverseString(prefix);
//     printf("The Prefix expression is: %s\n", prefix);
// }

// int main() {
//     char str[] = "A*(B+C)/D-G";
//     int length = strlen(str);
//     reverseString(str);

//     for (int i = 0; i < length; i++) {
//         if (str[i] == '(') {
//             str[i] = ')';
//         } else if (str[i] == ')') {
//             str[i] = '(';
//         }
//     }
//     infixTOprefix(str);

//     return 0;
// }

// /* Algorithm to convert the infix expression to postfix expression
// 1. Reverse the string(including the brackets)
// 2. convert the expression to postfix
// 3. again reverse and print
