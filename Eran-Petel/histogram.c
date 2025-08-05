/*
 * histogram.c
 *
 *  Created on: Jul 24, 2025
 *      Author: user
 */


#include <stdio.h>

#define MEX_LENGTH 20

int main(){

	int i, count, c;
	int nchars[MEX_LENGTH];

	count = 0;

	for(i = 0;i< MEX_LENGTH;i++){
		nchars[i] = 0;
	}
	while((c = getchar()) != EOF){
		if(c != ' ' && c != '\n' && c != '\t'){
			count++;
		}else if(count > 0 && count  < MEX_LENGTH){
			nchars[count]++;
			count = 0;
		}
	}
	printf("Print the Histogram:\n");
	printf("Number of chars in words: \n");
	for(i = 1;i < MEX_LENGTH;i++){
		printf("%2d %4d ", i, nchars[i]);
		while(nchars[i] > 0){
			printf("|");
			nchars[i]--;
		}
		printf("\n");
	}
	return 0;
}


