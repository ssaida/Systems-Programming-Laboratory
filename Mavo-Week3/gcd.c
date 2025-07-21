/*
 * gcd.c
 *
 *  Created on: Jul 9, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int m, n;
	int r;

	printf("Enter two numbers:\n");
	scanf("%d %d", &m, &n);

	if(m < n){
		r = m;
		m = n;
		n = r;

	}
	while(n > 0){
		r = m % n;
		m = n;
		n = r;
	}
	printf("The Gcd is %d\n", m);

	return 0;
}


