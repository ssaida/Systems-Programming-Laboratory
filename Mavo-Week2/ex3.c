/*
 * ex2.c
 *
 *  Created on: Jul 7, 2025
 *      Author: user
 */


#include <stdio.h>

int main()
{
	char ch;

	printf("Please enter a character between a-z or A-Z: ");
	scanf("%c",&ch);
	printf("Value: %d\nAscii: %c\n", ch, ch);
	printf("Value: %d\nAscii: %c\n", ch-=32, ch-=32);

    return 0;
}
