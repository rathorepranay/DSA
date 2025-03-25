#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct Queue* q) {
    if (q->r == q->f) {
        return 1;
    }
    return 0;
}

int isFull(struct Queue* q) {
    if (q->r == q->size - 1) {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is Full\n");
    } else {
        q->r++;
        q->arr[q->r] = data;  // Corrected assignment
    }
}

int dequeue(struct Queue* q) {
    int val = -1;
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    } else {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

int main() {
    struct Queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    if (q.arr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // BFS implementation
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d", j);  // Corrected format specifier
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    free(q.arr);  // Free allocated memory
    return 0;
}
