/*
 * mymat.h
 *
 *  Created on: May 28, 2025
 *      Author: Samer Saida
 */

#ifndef MYMAT_H
#define MYMAT_H

#define MAT_SIZE 4


typedef struct {
    double data[MAT_SIZE][MAT_SIZE];
} mat;

/*
 * Some functions to work on the matrices
 * Here is the list of the functions:
 */

/**
 * set 0.0 to every element at the matrix
 * @param m  - pointer to the matrix
 */
void zero_mat(mat *m);

/**
* sets values ​​in the matrix.
* Values ​​not provided in the list (up to 16) will be given 0.0.
* @param m is a pointer to the target matrix.
* @param parsed_values ​​is an array of actual values ​​to read.
* @param num_parsed is the number of values ​​in the parsed_values ​​array.
 */
void set_matrix_values(mat *m, double parsed_values[], int num_parsed);

/**
* prints the matrix in a 2D view.
* The values ​​will be printed with 2 digits after the decimal point and with an appropriate field width.
* @param m A pointer to the matrix to print.
 */
void print_mat_func(mat *m);

/**
* Concatenates two matrices and stores the result in a third matrix.
* result = a + b
* @param a pointer to the first matrix.
* @param b pointer to the second matrix.
* @param result pointer to the result matrix.
 */
void add_mat_func(mat *a, mat *b, mat *result);

/**
* Subtracts a second matrix from a first matrix and stores the result in a third matrix.
* result = a - b
* @param a pointer to the first matrix (from subtraction).
* @param b pointer to the second matrix (from subtraction).
* @param result pointer to the result matrix.
 */
void sub_mat_func(mat *a, mat *b, mat *result);

/**
* Multiplies two matrices and stores the result in a third matrix.
* result = a * b
* @param a is a pointer to the first matrix.
* @param b is a pointer to the second matrix.
* @param result is a pointer to the result matrix.
 */
void mul_mat_func(mat *a, mat *b, mat *result);

/**
* Multiplies a matrix by a scalar and stores the result in a second matrix.
* result = a * scalar
* @param a A pointer to the source matrix.
* @param scalar The scalar value to multiply.
* @param result A pointer to the result matrix.
 */
void scalar_mul_func(mat *a, double scalar, mat *result);

/**
* performs a transpose on a matrix and stores the result in a second matrix.
* result = transpose(source)
* @param source points to the source matrix.
* @param result points to the result (transposed) matrix.
 */
void trans_mat_func(mat *source, mat *result);

#endif /* MYMAT_H */
