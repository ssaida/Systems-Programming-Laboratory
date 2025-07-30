/*
 * intro.c
 *
 *  Created on: Jul 21, 2025
 *      Author: user
 */

 /* Week 1 intro */

#include <stdio.h>

#define MAX_LEN 100

int main()
{
   char str[MAX_LEN];
   printf("Enter your name: \n");
   fgets(str, MAX_LEN, stdin);
   printf("Your name is: %s",str);
   return 0;
}

