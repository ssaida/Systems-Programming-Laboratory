#include <stdio.h>

int main(void){
	int cel_temp, fahr_temp = 34;
	cel_temp = (fahr_temp - 32) / (212 - 32) * 100;
	
	printf("%d fahrenheit = %d celsius\n", fahr_temp, cel_temp);
	
	return 0;
}