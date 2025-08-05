/*
 * vertical-histogram.c
 *
 *  Created on: Jul 21, 2025
 *      Author: user
 */
#include <stdio.h>

#define LOWEST ' '
#define HIGHEST '~'


int main(){

	int len_freq[HIGHEST - LOWEST];
	int height;
	int c, i, k;

	for(i = 0;i<HIGHEST - LOWEST;i++){
			len_freq[i] = 0;
	}

	while((c = getchar()) != EOF){
		if(LOWEST <= c && c <= HIGHEST){
			len_freq[c-LOWEST]++;
			if(len_freq[c-LOWEST] >= height)
				height = len_freq[c-LOWEST];
		}
	}

	for(i = height;i > 0;i--){
		printf("%4d|", i);
		for(k = 0;k<HIGHEST - LOWEST;k++){
			if(len_freq[k] >= i)
				printf("#");
			else
				printf(" ");
		}
	}

}
