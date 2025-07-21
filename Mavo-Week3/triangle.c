/*
 * triangle.c
 *
 *  Created on: Jul 10, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int size;
	int i, j;
	int num_spaces;
	char letter;
	char lower_letter;


	printf("Enter a character (a-z):\n");
	scanf("%c", &letter);

	printf("Enter an Odd number between 1 - 21:\n");
	scanf("%d", &size);

	if(size < 1 && size > 21){
		printf("Size input error!\n");
		return 1;
	}
	if(size %2 == 0){
		printf("Size is not Odd!");
		return 1;
	}
	if(letter <  'A' && letter > 'Z'){
		printf("Letter input error!\n");
		return 1;
	}
/*
	for(i = 0;i <= size/2;i++){
		for(j = 0;j <= i;j++)
			printf(" ");

		for(k = 0;k <= size/2;k++)
			printf("%c", letter);
		printf("\n");
	}

	*/
	  for (i = size; i >= 1; i -= 2) {
        num_spaces = (size - i) / 2;
        for (j = 0; j < num_spaces; j++) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("%c", letter);
        }
        printf("\n");
    }

    lower_letter = letter + ('a' - 'A');
    for (i = 3; i <= size; i += 2) {
        num_spaces = (size - i) / 2;
        for (j = 0; j < num_spaces; j++) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("%c", lower_letter);
        }
        printf("\n");
    }

	return 0;
}


