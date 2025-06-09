/*
 * count.c
 *
 *  Created on: Jun 8, 2025
 *      Author: user
 */

#include <stdio.h>



int main(){
	int c;
	int ns, nt, nl;
	ns = nt = nl = 0;
	while((c = getchar()) != EOF){
		if(c == '\n')
			nl++;
		if(c == '\t')
			nt++;
		if(c == ' ')
			ns++;
	}
	printf("------------------\n");
	printf("Total Spaces: %d\n", ns);
	printf("Total Tabs: %d\n", nt);
	printf("Total lines: %d\n", nl);
	return 0;
}
