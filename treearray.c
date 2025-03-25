#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function prototypes
void insert(int tree[], int index, int value);
void display(int tree[], int n);

int main() {
    // Initialize an array to represent the tree
    int tree[MAX];

    // Fill the tree with -1 (indicating empty nodes)
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }

    // Insert values into the tree
    insert(tree, 0, 1);  // Insert root node (value = 1)
    insert(tree, 1, 2);  // Insert left child of root (value = 2)
    insert(tree, 2, 3);  // Insert right child of root (value = 3)
    insert(tree, 3, 4);  // Insert left child of node at index 1 (value = 4)
    insert(tree, 4, 5);  // Insert right child of node at index 1 (value = 5)

    // Display the tree
    printf("Binary Tree represented as an array:\n");
    display(tree, 10);  // Display the first 10 nodes

    return 0;
}

// Function to insert a value into the tree array
void insert(int tree[], int index, int value) {
    if (index >= MAX) {
        printf("Index out of bounds\n");
        return;
    }
    tree[index] = value;
}

// Function to display the tree array
void display(int tree[], int n) {
    for (int i = 0; i < n; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        } else {
            printf("_ ");  // Display empty nodes as '_'
        }
    }
    printf("\n");
}