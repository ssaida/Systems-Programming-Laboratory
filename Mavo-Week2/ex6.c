/*
 * ex6.c
 *
 *  Created on: Jul 7, 2025
 *      Author: user
 */


#include <stdio.h>
#include <math.h>

int main()
{
    int i = 2;
    double d;
    int x;
    int y;

    i = (i+6)/7;
    printf("i = %d\n", i);
    d = 42.0;
    printf("i = %d\n", i);
    i = 2.2/1.5;
    printf("i = %d\n", i);
    i = (i+6)/7;
    printf("i = %d\n", i);
    i = i - 7;
    printf("i = %d\n", i);
    i = 2.2 / 1.5;
    printf("i = %d\n", i);
    d = 42.0;
    printf("d = %f\n", d);
    d = d + i/100;
    printf("d = %f\n", d);
    d = 0; d--;
    printf("d = %f\n", d);
    d = 0.5;
    printf("d = %f\n", d);
    i = (d != 5) + d;
    printf("i = %d\n", i);
    d = 144;
    printf("d = %f\n", d);
    i = 12.5;
    printf("i = %d\n", i);
    x = (sqrt(d) >= pow(i, 2.0));
    printf("x = %d\n", x);
    d = (i-2) && (8*2.3);
    printf("d = %f\n", d);
    d = i || i;
    printf("d = %f\n", d);
    x = i--;
    printf("x = %d\n", x);
    y = --i;
    x = 0, y = 5;
    printf("x = %d\n", x);
    i = (x=y);
    d = sqrt(d) > pow(i, 2.0);
    printf("d = %f\n", d);


    /* Place your code here:
    XXXXXXXXXXXXXXXXXXXXX*/


    return 0;
}
