/*
 * day-in-week.c
 *
 *  Created on: Jul 8, 2025
 *      Author: user
 */

#include <stdio.h>

int main() {
    int dayOfWeek;

    /* Get input from the user */
    printf("Enter a number (1-7) representing the day of the week: ");
    scanf("%d", &dayOfWeek);

    /* Use switch-case-default to determine the day name */
    switch (dayOfWeek) {
        case 1:
            printf("It's Monday!\n");
            break; /* Exit the switch statement */
        case 2:
            printf("It's Tuesday!\n");
            break;
        case 3:
            printf("It's Wednesday!\n");
            break;
        case 4:
            printf("It's Thursday!\n");
            break;
        case 5:
            printf("It's Friday!\n");
            break;
        case 6:
            printf("It's Saturday!\n");
            break;
        case 7:
            printf("It's Sunday!\n");
            break;
        default: /* Executed if none of the above cases match */
            printf("Invalid number entered. Please enter a number between 1 and 7.\n");
    }

    return 0; /* Indicate successful execution */
}


