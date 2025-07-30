/*
 * bool.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */
#include <stdio.h>
#include <stdbool.h>

int main(){
	bool drunk = true;
	bool has_license = false;

	if(!has_license || drunk)
		printf("No Drive\n");

	return 0;
}
