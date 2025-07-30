/*
 * count.c
 *
 *  Created on: Jul 21, 2025
 *      Author: Samer Saida
 */
#include <stdio.h>

int main(){

	int ch;
	int ns, nt, nl;
	ns = nt = nl = 0;

	while((ch = getchar()) != EOF){
		if(ch == ' ')
			ns++;
		if(ch == '\t')
			nt++;
		if(ch == '\n')
			nl++;
	}
	printf("-----------------------------------\n");
	printf("Spaces: %d\nTabs: %d\nNew Lines: %d\n", ns, nt, nl);

	return 0;
}
