/*
 * sieve.c
 *
 *  Created on: Jul 11, 2025
 *      Author: user
 */
#include <stdio.h>

#define MAX 1000

void sieve_of_eratosthenes(int limit) {
	int is_prime[MAX + 1];
	int i, p;

    if (limit < 2 || limit > MAX) {
        printf("Invalid range. Please select a number between 2 and-%d\n", MAX);
        return;
    }
    for (i = 0; i <= limit; i++) {
        is_prime[i] = 1;
    }

    is_prime[0] = 0;
    is_prime[1] = 0;

    for (p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (i = p * p; i <= limit; i += p) {
                is_prime[i] = 0;
            }
        }
    }

    printf("Prime numbers till %d:\n", limit);
    for (i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter Upper limit %d): ", MAX);
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    sieve_of_eratosthenes(n);
    return 0;
}
