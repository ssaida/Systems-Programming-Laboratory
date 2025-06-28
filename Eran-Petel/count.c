/*
 * count.c
 *
 *  Created on: Jun 27, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int c;
	int ns, nt, nl;
	ns = nt = nl = 0;

	while( (c = getchar()) != EOF){
		if(c == ' ')
			ns++;
		if(c == '\n')
			nl++;
		if(c == '\t')
			nt++;
	}
	printf("----------------------");
	printf("\nTabs: %d\nSpaces: %d\nNewLines: %d\n", nt, ns, nl);
	return 0;
}
