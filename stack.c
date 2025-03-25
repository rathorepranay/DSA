#include <stdio.h>
#include <stdlib.h>
// Define Stack structure
struct Stack {
    int size;
    int top;
    int *arr;
};
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
int pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Khali h");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void traverse(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow");
    }
    else{
        printf("Stack from bottom to top\n");
        for(int i = 0; i<ptr->top; i++){
            printf("Elements at %d is : %d\n",i+1, ptr->arr[i]);
        }
    }
}

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
        printf("Enter element");
        scanf("%d", &value);
        push(s, value);
    }
    printf("The value popped is :%d",pop(s));
    //int d=pop(s);
    //printf("The numebr pop\n");
    traverse(s);
    
}