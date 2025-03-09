#include<stdio.h>
int main(void)
{
  int x = 0;
  float f = 3.14;
  char c = 'A';
  
  printf("%d!\n", x);
  printf("%.1f!\n", f);
  printf("%d!\n", c);
  
  printf("\n\n");
  
  while(x < 10){
    printf("%d %d\n", x, x);
    x++;
  }
  
  return 0;
}
