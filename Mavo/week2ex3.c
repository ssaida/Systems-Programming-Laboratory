/*
 * week2ex3.c
 *
 *  Created on: May 30, 2025
 *      Author: user
 */

#include <stdio.h>

int main()
{
	char ch;

	printf("Please enter a character between a-z or A-Z: ");
	scanf("%c",&ch);

	printf("%d\n", ch);
	printf("%c\n", ch);
	ch++;

	printf("%d\n", ch-32);
	printf("%c\n", ch-32);

    return 0;
}



