#include <stdio.h>
#include <limits.h>  /* For CHAR_BIT to get the number of bits in a byte */

/* Function that counts the number of zero bits in the binary representation of an unsigned int */
unsigned int bits_zero_count(unsigned int num);

int main() {
    unsigned int number;
    unsigned int zero_bits;

    /* Prompt the user for input */
    printf("Please enter a positive integer (unsigned int) in decimal: ");
    scanf("%u", &number);

    /* Call the function to count zero bits */
    zero_bits = bits_zero_count(number);

    /* Print the result */
    printf("The number entered: %u\n", number);
    printf("Number of zero bits in its binary representation: %u\n", zero_bits);

    return 0;
}
unsigned int bits_zero_count(unsigned int num) {
    unsigned int count = 0;
    unsigned int total_bits = sizeof(unsigned int) * CHAR_BIT;  /* Total bits in unsigned int */
    unsigned int i;

    /* Loop through each bit and check if it's 0 */
    for (i = 0; i < total_bits; i++) {
        if ((num & (1U << i)) == 0) {
            count++;
        }
    }

    return count;
}

