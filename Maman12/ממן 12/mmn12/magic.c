#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 5 /* size of the matrix. */

/* Function to read a matrix from standard input */
int readMatrix(int matrix[N][N]) {
    printf("Enter %d integers for matrix %dx%d, separated by whitespace:\n", N * N, N, N);
    int value;
    int count = 0;
    int allValues[N * N];
    char buffer[256];
    char *token;
    int i, j, k;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        token = strtok(buffer, " \t\n");
        while (token != NULL) {
            if (sscanf(token, "%d", &value) != 1) {
                fprintf(stderr, "Input error: Invalid value.\n");
                return 0;
            }
            if (value < 1 || value > N * N) {
                fprintf(stderr, "Input error: Value %d exceeds the allowed range (1 to %d).\n", value, N * N);
                return 0;
            }
            if (count < N * N) {
                allValues[count++] = value;
            } else {
                fprintf(stderr, "Input error: too many values.\n");
                return 0;
            }
            token = strtok(NULL, " \t\n");
        }
        if (count == N * N) break;
    }

    if (count < N * N) {
        fprintf(stderr, "Input error: Missing values. %d of %d required were received..\n", count, N * N);
        return 0;
    }

    /* Checking for duplicate values */
    for (i = 0; i < N * N; i++) {
        for (j = i + 1; j < N * N; j++) {
            if (allValues[i] == allValues[j]) {
                fprintf(stderr, "Input error: Value %d appears more than once.\n", allValues[i]);
                return 0;
            }
        }
    }

    k = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = allValues[k++];
        }
    }

    return 1;
}

/* Matrix printing function */
void printMatrix(const int matrix[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*  Function to check if the matrix is ​​a basic magic square */
int isMagicSquare(const int matrix[N][N]) {
    int magicSum = 0;
    int i, j;

    /*  Calculating the sum of the first row */
    for (j = 0; j < N; j++) {
        magicSum += matrix[0][j];
    }

    /* Checking the sum of the rows */
    for (i = 0; i < N; i++) {
        int rowSum = 0;
        for (j = 0; j < N; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != magicSum) {
            return 0;
        }
    }

    /* Checking the sum of the cols */
    for (j = 0; j < N; j++) {
        int colSum = 0;
        for (i = 0; i < N; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != magicSum) {
            return 0;
        }
    }

    /* Checking the sum of the main diagonal */
    int diag1Sum = 0;
    for (i = 0; i < N; i++) {
        diag1Sum += matrix[i][i];
    }
    if (diag1Sum != magicSum) {
        return 0;
    }

    /*  Checking the secondary diagonal sum */
    int diag2Sum = 0;
    for (i = 0; i < N; i++) {
        diag2Sum += matrix[i][N - 1 - i];
    }
    if (diag2Sum != magicSum) {
        return 0;
    }

    /*  Check that the values ​​are from 1 to N*N and appear exactly once (already done in the input) */

    return 1;
}

int main() {
    int matrix[N][N];

    if (readMatrix(matrix)) {
        printf("\nThe matrix entered is:\n");
        printMatrix(matrix);

        if (isMagicSquare(matrix)) {
            printf("\nThe matrix is ​​a basic magic square..\n");
        } else {
            printf("\nThe matrix is ​​not a basic magic square..\n");
        }
    }

    return 0;
}
