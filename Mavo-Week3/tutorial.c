/*
 * tutorial.c
 *
 *  Created on: Jul 9, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	int x = 6;
	int i = 3, j = 5;
	int num1, num2, num3;
	int count = 1;
	printf("Q-1\n");
	if ( 3 < x && x < 5 )
	 printf("oops...\n");
	else
	 printf("great!\n");

	printf("Q-2\n");


	if (i == j)
	 printf("Same\n");
	else
	 printf("Different\n");

	printf("Q-3\n");
	i = 0, j = 0;
	if (i == j)
	 printf("Same\n");
	else
	 printf("Different\n");

	printf("Q-4\n");
	printf("Enter 3 numbers:\n");
	scanf("%d %d %d",&num1, &num2, &num3);
	if(num1 > num2 && num1 > num3 && num2 > num3)
		printf("Sequences from biggest number to small:\n%d\n%d\n%d\n", num1, num2, num3);
	else if(num2 > num1 && num2 > num3 && num1 > num3)
		printf("Sequences from biggest number to small:\n%d\n%d\n%d\n", num2, num1, num3);
	else if(num1 > num2 && num1 > num3 && num3 > num2)
		printf("Sequences from biggest number to small:\n%d\n%d\n%d\n", num1, num3, num2);
	else if(num2 > num1 && num2 > num3 && num3 > num1)
		printf("Sequences from biggest number to small:\n%d\n%d\n%d\n", num2, num3, num1);
	else if(num3 > num1 && num3 > num2 && num1 > num2)
		printf("Sequences from biggest number to small:\n%d\n%d\n%d\n", num3, num1, num2);
	else
		printf("Sequences from biggest number to small:\n%d\n%d\n%d", num3, num2, num1);

	printf("Loop - 1\n");

	for (; count <= 5 ; count++){
		int count = 1;
		printf("%d\n", count);
	}
	printf("Loop - 2\n");
	while (count <= 5){
		int count = 1;
		printf("%d\n", count);
		count++;
	}
	return 0;
}
