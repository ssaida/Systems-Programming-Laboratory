/*
 * week1.c
 *
 *  Created on: May 28, 2025
 *      Author: user
 */

/* Week 1 intro */

#include <stdio.h>

#define MAX_LEN 100

int main()
{
   char str[MAX_LEN];
   printf("Enter your name: ");
   fgets(str, MAX_LEN, stdin);
   printf("Your name is: %s\n\n",str);
   return 0;
}
