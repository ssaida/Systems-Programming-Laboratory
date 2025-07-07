/*
 * chars.c
 *
 *  Created on: Jul 2, 2025
 *      Author: user
 */
#include <stdio.h>

int main() {
	int i;

	printf("ASCII Table:\n");
    printf("Dec\tHex\tChar\n");
    printf("---\t---\t----\n");


    for (i = 0; i <= 127; i++) {


        if (i >= 0 && i <= 31) {
            printf("%d\t0x%02X\t[Ctrl]\n", i, i);
        } else if (i == 127) {
            printf("%d\t0x%02X\t[DEL]\n", i, i);
        } else {
            printf("%d\t0x%02X\t%c\n", i, i, (char)i);
        }
    }

    return 0;
}
