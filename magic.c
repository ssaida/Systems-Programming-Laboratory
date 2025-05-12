#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5
#define SIZE (N * N)

/* Function declarations */
void printMatrix(int matrix[N][N]);
bool readInput(int matrix[N][N]);
bool isMagicSquare(int matrix[N][N]);
bool checkUnique(int arr[], int size);
bool checkBounds(int arr[], int size);

int main() {
    int matrix[N][N];

    /* Prompt the user for input */
    printf("Please enter %d integers between 1 and %d (separated by spaces):\n", SIZE, SIZE);

    /* Read input and validate it */
    if (!readInput(matrix)) {
        fprintf(stderr, "Input error: Please ensure exactly %d valid, unique, in-range integers are provided.\n", SIZE);
        return 1;
    }

    /* Print the matrix */
    printf("Input matrix:\n");
    printMatrix(matrix);

    /* Check if the matrix is a basic magic square */
    if (isMagicSquare(matrix)) {
        printf("This is a basic magic square.\n");
    } else {
        printf("This is NOT a basic magic square.\n");
    }

    return 0;
}

/* Function to print the matrix in a formatted way */
void printMatrix(int matrix[N][N]) {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function to read input from stdin and validate */
bool readInput(int matrix[N][N]) {
    int input[SIZE];
    int count = 0;
    int extra;
    int i;

    /* Read up to SIZE integers */
    while (count < SIZE && scanf("%d", &input[count]) == 1) {
        count++;
    }

    /* Not enough values */
    if (count < SIZE) return false;

    /* Too many values */
    if (scanf("%d", &extra) == 1) return false;

    /* Check bounds and uniqueness */
    if (!checkBounds(input, SIZE) || !checkUnique(input, SIZE)) return false;

    /* Transfer the input to a 2D matrix */
    for (i = 0; i < SIZE; i++) {
        matrix[i / N][i % N] = input[i];
    }

    return true;
}

/* Function to ensure all values are within the allowed range */
bool checkBounds(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] < 1 || arr[i] > SIZE) {
            return false;
        }
    }
    return true;
}

/* Function to ensure all values are unique */
bool checkUnique(int arr[], int size) {
    bool seen[SIZE + 1] = {false};  /* Index 1 to SIZE */
    int i;

    for (i = 0; i < size; i++) {
        if (seen[arr[i]]) return false;
        seen[arr[i]] = true;
    }
    return true;
}

/* Function to check if the matrix is a basic magic square */
bool isMagicSquare(int matrix[N][N]) {
    int i, j;
    int magicSum = 0;
    int rowSum, colSum;
    int diag1, diag2;

    /* Calculate sum of the first row */
    for (j = 0; j < N; j++) {
        magicSum += matrix[0][j];
    }

    /* Check rows */
    for (i = 1; i < N; i++) {
        rowSum = 0;
        for (j = 0; j < N; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != magicSum) return false;
    }

    /* Check columns */
    for (j = 0; j < N; j++) {
        colSum = 0;
        for (i = 0; i < N; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != magicSum) return false;
    }

    /* Check main diagonal */
    diag1 = 0;
    for (i = 0; i < N; i++) {
        diag1 += matrix[i][i];
    }
    if (diag1 != magicSum) return false;

    /* Check secondary diagonal */
    diag2 = 0;
    for (i = 0; i < N; i++) {
        diag2 += matrix[i][N - 1 - i];
    }
    if (diag2 != magicSum) return false;

    return true;
}


