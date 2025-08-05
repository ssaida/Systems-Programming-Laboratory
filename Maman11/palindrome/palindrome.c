#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/**
function check if we could read a string backward as regular
*/
int palindrome(char s[]);

#define MAX_LENGTH 81 /* maximum chars is 80, and final char to end the string! */

int main() {
    char inputString[MAX_LENGTH];

    printf("Enter a string to check palindrome\n", MAX_LENGTH - 1);
    fgets(inputString, MAX_LENGTH, stdin);

    /* the fgets remove the new line */
    inputString[strcspn(inputString, "\n")] = 0;

    printf("The string is: %s\n", inputString);

    if (palindrome(inputString)) {
        printf("The string %s is Palindrome.\n", inputString);
    } else {
        printf("The string %s is  NOT Palindrome.\n", inputString);
    }

    return 0;
}
int palindrome(char s[]) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        /* skip spaces from the left side */
        while (left < right && (s[left] == ' ' || s[left] == '\t')) {
            left++;
        }
        /*  skip spaces from the righ side */
        while (left < right && (s[right] == ' ' || s[right] == '\t')) {
            right--;
        }

        if (s[left] != s[right]) {
            return 0; //Not a Palindrome
        }
        left++;
        right--;
    }
    return 1; /* if we reach this line, the string is Palindrome */
}


