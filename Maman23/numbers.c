/*
 * numbers.c
 *
 *  Created on: Jun 10, 2025
 *      Author: user
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Printing errors and terminating the program */
void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

/* Function that converts an integer (0-99) to English words */
const char *number_to_words(int num) {
	/* Array for single digits and 10-19 */
    const char *ones[] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };

    /* array for tens */
    const char *tens[] = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    /* Static so that the array will exist even after the function finishes running
     Maximum size: "ninety nine" + null terminator */
    static char result[20];

    if (num < 0 || num > 99) {
    	/* The task assumes that the input is valid in the range 0-99, but this is a good check in general.
    	in this case, we will return an empty string or an error message.
    	since the instruction is that the input is valid, this code should not go here. */
        return "";
    }

    if (num < 20) {
        /* numbers 0 - 19 */
        sprintf(result, "%s", ones[num]);
    } else {
    	/* numbers 20 - 99 */
        int ten = num / 10;
        int one = num % 10;
        if (one == 0) {
        /* etc 20, 30, 40 */

            sprintf(result, "%s", tens[ten]);
        } else {
        	/* etc 21, 35, 99 */
            sprintf(result, "%s %s", tens[ten], ones[one]);
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    FILE *inputFile = stdin;
    FILE *outputFile = stdout;
    int num;

    /* checking the number of arguments on the command line */
    if (argc > 3) {
        print_error("Too many arguments. Usage: program [input_file] [output_file]");
    }

    /* Argument handling */
    if (argc >= 2) {
    	/* Input file specified */
        inputFile = fopen(argv[1], "r");
        if (inputFile == NULL) {
            print_error("Could not open input file.");
        }
    }

    if (argc == 3) {
    	/* output file specified */
        outputFile = fopen(argv[2], "w");
        if (outputFile == NULL) {
        	/* If the output file is not opened, and the input file is opened (not stdin), it must be closed. */
            if (inputFile != stdin) {
                fclose(inputFile);
            }
            print_error("Could not open output file.");
        }
    }

    /* Reading numbers from input, converting and printing to output */
    while (fscanf(inputFile, "%d", &num) == 1) {
        fprintf(outputFile, "%s\n", number_to_words(num));
    }

    /* Close files if they are not standard I/O files */
    if (inputFile != stdin) {
        fclose(inputFile);
    }
    if (outputFile != stdout) {
        fclose(outputFile);
    }

    return EXIT_SUCCESS; /* Successful completion of the program */
}



