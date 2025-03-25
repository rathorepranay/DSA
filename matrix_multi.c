#include <stdio.h>

int main() {
    int m, n, p;
    
    // Input the dimensions of the matrices
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter the number of columns of the second matrix: ");
    scanf("%d", &p);

    // Declare matrices A, B, and C
    int A[m][n], B[n][p], C[m][p];

    // Initialize the result matrix C with zeros
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }

    // Input matrix A
    printf("Enter elements of the first matrix (A):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input matrix B
    printf("Enter elements of the second matrix (B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix multiplication logic
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Output the result matrix C
    printf("Resultant matrix C after multiplication:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}