// INFIX TO POSTFIX
// INFIX TO PREFIX




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define MAX 100

char stack[MAX];
int top = -1;

int emptystack()
{
    return top == -1;
}

int isfull()
{
    return top == MAX - 1;
}

void push(char c)
{
    if (!isfull())
    {
        stack[++top] = c;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

char pop()
{
    if (!emptystack())
    {
        return stack[top--];
    }
    else
    {
        printf("Stack Underflow\n");
        return '\0';
    }
}

char peek()
{
    if (!emptystack())
    {
        return stack[top];
    }
    else
    {
        return '\0';
    }
}

int precedence(char op)
{
    switch (op)
    {
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

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void infixTOpostfix(char s[], char postfix[])
{
    int k = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        if (isOperand(c))
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (!emptystack() && peek() != '(')
            {
                postfix[k++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        else if (isOperator(c))
        {
            while (!emptystack() && precedence(peek()) >= precedence(c))
            {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (!emptystack())
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
}

int evaluatePostfix(char postfix[])
{
    int evalStack[MAX];
    int evalTop = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];

        if (c >= '0' && c <= '9')
        {
            evalStack[++evalTop] = c - '0';
        }
        else if (isOperator(c))
        {
            int val2 = evalStack[evalTop--];
            int val1 = evalStack[evalTop--];
            switch (c)
            {
            case '+':
                evalStack[++evalTop] = val1 + val2;
                break;
            case '-':
                evalStack[++evalTop] = val1 - val2;
                break;
            case '*':
                evalStack[++evalTop] = val1 * val2;
                break;
            case '/':
                evalStack[++evalTop] = val1 / val2;
                break;
            case '^':
                evalStack[++evalTop] = pow(val1, val2);
                break;
            }
        }
    }
    return evalStack[evalTop];
}

int main()
{
    char str[] = "3+4*(2-7)/5";
    char postfix[100];

    infixTOpostfix(str, postfix);
    printf("The Postfix expression is: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("The result of evaluation is: %d\n", result);

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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// INFIX TO PREFIX 
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h> 

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

// int isOperand(char c) {
//     return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
// }

// void infixTOpostfix(char s[], char postfix[]) {
//     int k = 0;
    
//     for (int i = 0; s[i] != '\0'; i++) {
//         char c = s[i];
        
//         if (isOperand(c)) {
//             postfix[k++] = c;
//         } else if (c == '(') {
//             push(c);
//         } else if (c == ')') {
//             while (!emptystack() && peek() != '(') {
//                 postfix[k++] = pop();
//             }
//             pop(); // Remove '(' from stack
//         } else if (isOperator(c)) {
//             while (!emptystack() && precedence(peek()) >= precedence(c)) {
//                 postfix[k++] = pop();
//             }
//             push(c);
//         }
//     }
//     while (!emptystack()) {
//         postfix[k++] = pop();
//     }
//     postfix[k] = '\0'; // Null-terminate the postfix expression
// }

// void infixTOprefix(char s[], char prefix[]) {
//     char temp[MAX];
//     reverseString(s);

//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == '(') {
//             s[i] = ')';
//         } else if (s[i] == ')') {
//             s[i] = '(';
//         }
//     }

//     infixTOpostfix(s, temp);
//     reverseString(temp);
//     strcpy(prefix, temp);
// }

// int evaluatePrefix(char prefix[]) {
//     int evalStack[MAX];
//     int evalTop = -1;
//     int length = strlen(prefix);
    
//     for (int i = length - 1; i >= 0; i--) {
//         char c = prefix[i];
        
//         if (c >= '0' && c <= '9') {
//             evalStack[++evalTop] = c - '0';
//         } else if (isOperator(c)) {
//             int val1 = evalStack[evalTop--];
//             int val2 = evalStack[evalTop--];
//             switch (c) {
//                 case '+': evalStack[++evalTop] = val1 + val2; break;
//                 case '-': evalStack[++evalTop] = val1 - val2; break;
//                 case '*': evalStack[++evalTop] = val1 * val2; break;
//                 case '/': evalStack[++evalTop] = val1 / val2; break;
//                 case '^': evalStack[++evalTop] = pow(val1, val2); break;
//             }
//         }
//     }
//     return evalStack[evalTop];
// }

// int main() {
//     char str[] = "3+4*(2-7)/5";
//     char prefix[MAX];

//     infixTOprefix(str, prefix);
//     printf("The Prefix expression is: %s\n", prefix);

//     int result = evaluatePrefix(prefix);
//     printf("The result of evaluation is: %d\n", result);
    
//     return 0;
// }

// /* Algorithm to convert the infix expression to postfix expression
// 1. Reverse the string(including the brackets)
// 2. convert the expression to postfix
// 3. again reverse and print