/*
 * name.c
 *
 *  Created on: Jul 25, 2025
 *      Author: Samer Saida
 *
 * Week 1 name
 *
*/

#include <stdio.h>

#define MAX_LEN 100

int main()
{
   char str[MAX_LEN];
   printf("Enter your name: ");
   fgets(str, MAX_LEN, stdin);
   printf("Your name is: %s",str);
   return 0;
}
