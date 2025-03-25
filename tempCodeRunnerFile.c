#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
    int size;
    int top;
    char *arr;
};

// Function to check if stack is empty
int isEmpty(struct Stack *sp) {
    return sp->top == -1;
}

// Function to check if stack is full
int isFull(struct Stack *sp) {
    return sp->top == sp->size - 1;
}

// Function to return the top element of the stack
char stackTop(struct Stack* sp) {
    return sp->arr[sp->top];
}

// Function to push an element to the stack
void push(struct Stack *sp, char in) {
    if (isFull(sp)) {
        printf("Stack Overflow\n");
    } else {
        sp->top++;
        sp->arr[sp->top] = in;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        char ch = sp->arr[sp->top];
        sp->top--;
        return ch;
    }
}

// Function to check if a character is an operator
int isOperator(char i) {
    return (i == '+' || i == '-' || i == '*' || i == '/' || i == '%');
}

// Function to get the precedence of an operator
int precedence(char i) {
    if (i == '/' || i == '*' || i == '%')
        return 3;
    if (i == '+' || i == '-')
        return 1;
    return 0;
}

// Function to convert infix expression to postfix
char* infixtopostfix(char *infix) {
    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    
    char *postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // For infix traversal
    int j = 0; // For postfix traversal
    
    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) { // If operand, add to postfix
            postfix[j] = infix[i];
            j++;
            i++;
        } else { // If operator, handle precedence
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }
    
    // Pop all remaining operators from the stack
    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
    return postfix;
}

int main() {
    char infix[50];
    printf("Enter your expression: ");
    scanf("%s", infix);
    printf("Postfix Expression is: %s\n", infixtopostfix(infix));
    return 0;
}
