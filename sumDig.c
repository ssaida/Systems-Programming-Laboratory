#include<stdio.h>
int sumDigits(int);
int main(void)
{
  int num;
  printf("Enter a number to calculate sum Digits:\n");
  scanf("%d", &num);
  printf("Sum digits: %d\n", sumDigits(num));
  return 0;
}
int sumDigits(int number){
  int res = 0;
  while(number > 0){
    res += number % 10;
    number /= 10;
  }
  return res;
}
