/*
 * gitbits.c
 *
 *  Created on: Jul 6, 2025
 *      Author: user
 */
#include <stdio.h>

unsigned gitbits(unsigned, int, int);

int main(){
	printf(gitbits(10, 10, 4));
	return 0;
}

unsigned gitbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}



