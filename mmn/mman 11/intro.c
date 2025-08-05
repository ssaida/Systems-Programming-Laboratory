#include<stdio.h>

int palindrome(int);

int main(){
	int number = 9;
	printf("%d", number);
	return 0;
}

int palindrome(int num){
	int sum = 0;
	while(num > = 0){
		sum += num % 10;
		num  /= 10;
	}
	return sum;
}