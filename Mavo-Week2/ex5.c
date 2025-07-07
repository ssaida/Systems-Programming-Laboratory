/*
 * ex5.c
 *
 *  Created on: Jul 7, 2025
 *      Author: user
 */


#include <stdio.h>

int main()
{
    double num;
    printf("Enter a floating point number:\n");
    scanf("%lf", &num);
    printf("%010.3f\n", num);

    return 0;
}

