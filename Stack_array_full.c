#include <stdio.h>
#include <stdlib.h>
// Define Stack structure
struct Stack {
    int size;
    int top;
    int *arr;
};

// Function to check if stack is empty
int isEmpty(struct Stack *ptr) {
    return ptr->top == -1;
}

// Function to check if stack is full
int isFull(struct Stack *ptr) {
    return ptr->top == ptr->size - 1;
}

// Function to push an element onto the stack
void push(struct Stack *ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %d onto the stack.\n", val);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Pushed %d onto the stack.\n", val);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Function to traverse and print all elements in the stack
void traverse(struct Stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack elements from bottom to top:\n");
        for (int i = 0; i <= ptr->top; i++) {
            printf("Element %d: %d\n", i + 1, ptr->arr[i]);
        }
    }
}

// Function to get the top element of the stack
int stackTop(struct Stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is Empty. No top element.\n");
        return -1;
    }
    return ptr->arr[ptr->top];
}

// Function to get the bottom element of the stack
int stackBottom(struct Stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is Empty. No bottom element.\n");
        return -1;
    }
    return ptr->arr[0];
}

// Main function
int main() {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack)); // Allocate memory for the stack
    if (s == NULL) {
        printf("Memory allocation for stack structure failed.\n");
        return 1;
    }

    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int)); // Allocate memory for the stack array
    if (s->arr == NULL) {
        printf("Memory allocation for array failed.\n");
        free(s);
        return 1;
    }

    // Adding elements to the stack
    int n;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(s, value);
    }

    // Pushing an additional element
    int value;
    printf("\nEnter an additional value to push: ");
    scanf("%d", &value);
    push(s, value);

    // Display stack after pushing
    printf("\nStack after pushing elements:\n");
    printf("-----------------------------------------------------\n");
    traverse(s);

    // Pop an element from the stack
    printf("\nPopping an element from the stack:\n");
    printf("-----------------------------------------------------\n");
    int poppedValue = pop(s);
    if (poppedValue != -1) {
        printf("Popped element: %d\n", poppedValue);
    }

    // Display stack after popping
    printf("\nStack after popping an element:\n");
    printf("-----------------------------------------------------\n");
    traverse(s);

    // Display top and bottom elements
    printf("\n-----------------------------------------------------\n");
    printf("Top element: %d\n", stackTop(s));
    printf("Bottom element: %d\n", stackBottom(s));

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;
}
