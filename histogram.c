/*
 * histogram.c
 *
 *  Created on: Jun 27, 2025
 *      Author: user
 */
#include <stdio.h>

#define MAX_LENGTH 20

int main(){
	int i, count, c;
	int nchars[MAX_LENGTH];

	count = 0;

	/* init the nchars array */
	for(i = 1;  i < MAX_LENGTH; ++i)
		nchars[i] = 0;


	while( (c = getchar()) != EOF){
		if(c != ' ' && c != '\n' && c != '\t'){
			++count;
		}else if(count > 0 && count < MAX_LENGTH){
			++nchars[count];
			count = 0;
		}
	}

	/* printf the histogram */

	printf("Number of chars in words: \n");
	for(i = 1; i < MAX_LENGTH; i++){
		printf("%2d %4d", i, nchars[i]);
		while(nchars[i] > 0){
			printf("|");
			--nchars[i];
		}
	}
		printf("\n");
	return 0;
}
