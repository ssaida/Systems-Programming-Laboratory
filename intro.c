#include<stdio.h>

int main(void){
  int num1, num2, sum;
  printf("Please enter two numbers:\n");
  scanf("%d %d", &num1, &num2);
  sum = num1 + num2;
  printf("The sum of two two numbers is %d\n", sum);
  printf("The average of two two numbers is %d\n", sum/2);
  return 0;
}

