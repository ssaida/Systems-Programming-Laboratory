/*
 * ex3.c
 *
 *  Created on: Jul 28, 2025
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
	if(ch == 'z')
		printf("%c\n", ch);
	else
		printf("There is no letter after z\n");

    return 0;
}
