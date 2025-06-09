/*
 * gcd.c
 *
 *  Created on: Jun 3, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int m, n;
	int r;
	printf("Enter m and n\n");
	scanf("%d %d", &n, &m);

	while(n > 0){
		r = m %n;
		m = n;
		n = r;
	}

	printf("The Gcd is %d\n", m);
	return 0;
}
