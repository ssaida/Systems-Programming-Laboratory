/*
 * mamat.c
 *
 *  Created on: May 25, 2025
 *      Author: Samer Saida
 */

#include "mymat.h"
#include <stdio.h>
#include <string.h>

/**
 *  Initialize 0.0 to every element at the matrix
 */
void zero_mat(mat *m) {
    int i, j;
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            m->data[i][j] = 0.0;
        }
    }
}

/**
 * Sets values ​​in a matrix, resets unspecified values
 */
void set_matrix_values(mat *m, double parsed_values[], int num_parsed) {
    int k = 0; /* Counter for the array of values ​​captured */
    int i, j;
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            if (k < num_parsed) {
                m->data[i][j] = parsed_values[k++];
            } else {
                m->data[i][j] = 0.0; /* set 0.0 to the other values in case */
            }
        }
    }
}

/**
 *  Printing the matrix
 */
void print_mat_func(mat *m) {
    int i, j;
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
        	/*  Print with 2 digits after the point, a field width of 7 characters and an extra space */
            printf("%7.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

/**
 * concatenating two matrices
 */
void add_mat_func(mat *a, mat *b, mat *result) {
    int i, j;
    mat temp_result; /* Using an intermediate matrix in case result is the same as a or b */
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            temp_result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    *result = temp_result; /* Copying a structure (struct copy) */
}

/**
 * Writes a second matrix into a first matrix.
 */
void sub_mat_func(mat *a, mat *b, mat *result) {
    int i, j;
    mat temp_result;
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            temp_result.data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    *result = temp_result;
}

/**
 *  Multiplies two matrices.
 */
void mul_mat_func(mat *a, mat *b, mat *result) {
    int i, j, k;
    mat temp_result;
    zero_mat(&temp_result); /* It is important to reset the temporary result matrix. */

    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            for (k = 0; k < MAT_SIZE; k++) {
                temp_result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    *result = temp_result;
}

/**
 *  Multiplies a matrix by a scalar.
 */
void scalar_mul_func(mat *a, double scalar, mat *result) {
    int i, j;
    mat temp_result;
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            temp_result.data[i][j] = a->data[i][j] * scalar;
        }
    }
    *result = temp_result;
}

/**
 *  Performs a transpose to the matrix.
 */
void trans_mat_func(mat *source, mat *result) {
    int i, j;
    mat temp_result;
    for (i = 0; i < MAT_SIZE; i++) {
        for (j = 0; j < MAT_SIZE; j++) {
            temp_result.data[i][j] = source->data[j][i];
        }
    }
    *result = temp_result;
}

