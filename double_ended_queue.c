#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* f = NULL;
struct Node* r = NULL;

void enqueuef(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Queue overflow\n");
    } else {
        n->data = val;
        n->next = f;
        f = n;
        if (r == NULL) { // If the queue was empty
            r = n;
        }
        printf("Value enqueued in front: %d\n", val);
    }
}

void enqueuer(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Queue overflow\n");
    } else {
        n->data = val;
        n->next = NULL;
        if (f == NULL) {
            f = r = n;
        } else {
            r->next = n;
            r = n;
        }
        printf("Value enqueued in rear: %d\n", val);
    }
}

int dequeuef() {
    int val = -1;
    if (f == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* ptr = f;
        val = f->data;
        f = f->next;
        if (f == NULL) { // If the queue becomes empty
            r = NULL;
        }
        free(ptr);
    }
    return val;
}

int dequeuer() {
    int val = -1;
    if (f == NULL) {
        printf("Queue is empty\n");
    } else if (f == r) { // Only one element
        val = f->data;
        free(f);
        f = r = NULL;
    } else {
        struct Node* ptr = f;
        while (ptr->next != r) {
            ptr = ptr->next;
        }
        val = r->data;
        free(r);
        r = ptr;
        r->next = NULL;
    }
    return val;
}

void linkedListTraversal(struct Node* ptr) {
    printf("Printing the elements of this linked list:\n");
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    enqueuef(51);
    enqueuef(52);
    enqueuef(53);
    enqueuef(54);
    enqueuer(20);
    
    linkedListTraversal(f);

    printf("Dequeued from rear: %d\n", dequeuer());
    linkedListTraversal(f);

    return 0;
}
