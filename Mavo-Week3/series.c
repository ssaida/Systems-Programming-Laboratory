/*
 * series.c
 *
 *  Created on: Jul 10, 2025
 *      Author: user
 */


#include <stdio.h>
#include <math.h>



int main() {
    int n; /* Declare an integer variable for user input 'n'*/
    int an; /* Declare a long long variable to store a_n to handle potentially large numbers*/
    int i;


    printf("Please enter a non-negative integer (n): ");


    scanf("%d", &n);


    if (n < 0) {
        printf("Error: n must be a non-negative integer.\n");
        return 1;
    }


    if (n == 0) {
        an = 3;
    } else {
        /* Calculate a_n iteratively */
        /* We start with a0 and compute up to an */
        an = 3; /* Initialize an with a0 */
        for (i = 1; i <= n; i++) {
            an = 3 * an + 4; /* Apply the recursive formula */
        }
    }


    printf("The value of a%d is: %d\n", n, an);

    return 0;
}

