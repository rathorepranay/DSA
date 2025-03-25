#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack* ptr) {
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack* ptr) {
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int main() {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack)); // Allocate memory for the stack structure
    if (s == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    s->size = 8;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int)); // Allocate memory for the array
    if (s->arr == NULL) {
        printf("Memory allocation for array failed");
        free(s); // Free the stack structure memory
        return 1;
    }

    // Adding elements by user
    for (int i = 0; i < s->size; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &s->arr[i]); // Pass the address of the element
        s->top++;
    }

    // Checking if the stack is empty or not
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;
}
