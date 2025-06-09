#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include "mymat.h"
#include "mymat.c"

#define MAX_LINE_LEN 512
#define MAX_COMMAND_LEN 20
#define MAX_MAT_NAME_LEN 10
#define MAX_NUMBERS_FOR_READ_MAT (MAT_SIZE * MAT_SIZE)


/* Define the six global matrices */
mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;

/* An array of pointers to matrices and their names, for easy access */
mat *all_matrices[] = {&MAT_A, &MAT_B, &MAT_C, &MAT_D, &MAT_E, &MAT_F};
const char *matrix_names[] = {"MAT_A", "MAT_B", "MAT_C", "MAT_D", "MAT_E", "MAT_F"};
const int num_defined_matrices = sizeof(all_matrices) / sizeof(all_matrices[0]);

/* --- Auxiliary functions for input analysis --- */

/**
 * Skips whitespace characters (spaces, tabs) and returns a pointer to the first non-whitespace character.
 */
char *skip_whitespace(char *ptr) {
    while (*ptr && isspace((unsigned char)*ptr)) {
        ptr++;
    }
    return ptr;
}

/**
 * Prints an error message in a fixed format.
 */
void report_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

/**
* Retrieves a pointer to a matrix by its name.
* @param name The name of the matrix (e.g. "MAT_A").
* @return A pointer to the matrix if found, otherwise NULL.
 */
mat *get_matrix_by_name(const char *name) {
    int i;
    for (i = 0; i < num_defined_matrices; i++) {
        if (strcmp(name, matrix_names[i]) == 0) {
            return all_matrices[i];
        }
    }
    return NULL;
}

/* --- Helper functions for parsing specific arguments --- */

/**
* Parses a matrix name argument.
* @param current_pos_ptr Points to the pointer of the current position in the input string.
* @param matrix_arg Points to a variable that will receive the pointer to the parsed matrix.
* @param error_flag Points to a flag indicating whether an error occurred.
* @return true if the parsing was successful, false otherwise.
 */
bool parse_matrix_operand(char **current_pos_ptr, mat **matrix_arg, bool *error_flag) {
    char mat_name_buffer[MAX_MAT_NAME_LEN + 1];
    int i = 0;
    int j;


    if (*error_flag) return false;

    *current_pos_ptr = skip_whitespace(*current_pos_ptr);

    if (**current_pos_ptr == '\0' || **current_pos_ptr == ',') {
        report_error("Missing argument (expected matrix name).");
        *error_flag = true;
        return false;
    }

    while (**current_pos_ptr && !isspace((unsigned char)**current_pos_ptr) && **current_pos_ptr != ',' && i < MAX_MAT_NAME_LEN) {
        mat_name_buffer[i++] = *(*current_pos_ptr)++;
    }
    mat_name_buffer[i] = '\0';

    if (i == 0) {
        report_error("Missing argument (expected matrix name).");
        *error_flag = true;
        return false;
    }
    if (i == MAX_MAT_NAME_LEN && **current_pos_ptr && !isspace((unsigned char)**current_pos_ptr) && **current_pos_ptr != ',') {
        report_error("Matrix name too long.");
        *error_flag = true;
        while (**current_pos_ptr && !isspace((unsigned char)**current_pos_ptr) && **current_pos_ptr != ',') {
            (*current_pos_ptr)++;
        }
        return false;
    }

    /* Check that the matrix name is in uppercase only (except '_') */
    for(j=0; mat_name_buffer[j]; j++){
        if(!(isupper((unsigned char)mat_name_buffer[j]) || mat_name_buffer[j] == '_')){
             report_error("Undefined matrix name (must be in uppercase and underscore only).");
             *error_flag = true;
             return false;
        }
    }


    *matrix_arg = get_matrix_by_name(mat_name_buffer);
    if (*matrix_arg == NULL) {
        report_error("Undefined matrix name.");
        *error_flag = true;
        return false;
    }
    return true;
}

/**
 * Parses a comma separating arguments.
 */
bool parse_comma_separator(char **current_pos_ptr, bool *error_flag) {
    char *temp_ptr;
    if (*error_flag) return false;

    *current_pos_ptr = skip_whitespace(*current_pos_ptr);
    if (**current_pos_ptr == ',') {
        (*current_pos_ptr)++;

        /* Check if there is another comma immediately after (with possible spaces) */
        temp_ptr = skip_whitespace(*current_pos_ptr);
        if (*temp_ptr == ',') {
            report_error("Multiple consecutive ',' .");
            *error_flag = true;
            return false;
        }
        if (*temp_ptr == '\0') {
             report_error("Missing argument after ','");
             *error_flag = true;
             return false;
        }

        return true;
    } else if (**current_pos_ptr == '\0') { /*end line insteed ','  */
        report_error("Missing argument (comma and additional argument expected).");
        *error_flag = true;
        return false;
    } else {
        report_error("Comma missing.");
        *error_flag = true;
        return false;
    }
}

/**
 * Parses a scalar value (real number) argument.
 */
bool parse_scalar_operand(char **current_pos_ptr, double *scalar_val, bool *error_flag) {
    char *start_ptr;
    char *end_ptr;
    char *check_after_num;

    if (*error_flag) return false;

    *current_pos_ptr = skip_whitespace(*current_pos_ptr);
    start_ptr = *current_pos_ptr;

    if (**current_pos_ptr == '\0' || **current_pos_ptr == ',') {
        report_error("Missing argument (expected scalar value).");
        *error_flag = true;
        return false;
    }

    errno = 0;
    *scalar_val = strtod(start_ptr, &end_ptr);

    if (start_ptr == end_ptr) {
        report_error("Argument is not a scalar (real number required).");
        *error_flag = true;
        return false;
    }
    if (errno == ERANGE) {
        report_error("Scalar value out of range.");
        *error_flag = true;
        return false;
    }

    /* Check for extra characters after the number (before a comma or end of line) */
    check_after_num = skip_whitespace(end_ptr);
    if (*check_after_num != '\0' && *check_after_num != ',') {
        report_error("Invalid characters after a scalar value.");
        *error_flag = true;
        return false;
    }

    *current_pos_ptr = end_ptr; /* Advance the main pointer to the end of the parsed number */
    return true;
}

/**
 * Parses a list of numbers for the read_mat command.
 */
bool parse_numbers_list_for_read_mat(char **current_pos_ptr, mat *target_matrix, bool *error_flag) {
    double numbers[MAX_NUMBERS_FOR_READ_MAT];
    int count = 0;
    char *start_num_ptr, *end_num_ptr;
    char *check_after_num;
    char *temp_ptr;

    if (*error_flag) return false;

    *current_pos_ptr = skip_whitespace(*current_pos_ptr);
    if (**current_pos_ptr == '\0') { /* No numbers after the first comma of read_mat */
        report_error("Missing argument (list of numbers required for read_mat).");
        *error_flag = true;
        return false;
    }

    while (**current_pos_ptr != '\0' && count < MAX_NUMBERS_FOR_READ_MAT) {
        start_num_ptr = skip_whitespace(*current_pos_ptr); /* Skip spaces before the number */

        if (*start_num_ptr == '\0') break; /* We have reached the end of the line, but maybe after a proper last comma */

        if (*start_num_ptr == ','){ /* Comma instead of a number (example read_mat MAT_A, , 1) */
            report_error("Multiple consecutive commas or a missing number in the list.");
            *error_flag = true;
            return false;
        }


        errno = 0;
        numbers[count] = strtod(start_num_ptr, &end_num_ptr);

        if (start_num_ptr == end_num_ptr) {
            report_error("Argument is not a real number in the read_mat list.");
            *error_flag = true;
            return false;
        }
        if (errno == ERANGE) {
            report_error("Number out of range in read_mat list.");
            *error_flag = true;
            return false;
        }

        /* Check for extra characters after the number (before a comma or end of line) */
        check_after_num = skip_whitespace(end_num_ptr);
         if (*check_after_num != '\0' && *check_after_num != ',') {
            report_error("Invalid characters after a number in the read_mat list.");
            *error_flag = true;
            return false;
        }

        count++;
        *current_pos_ptr = end_num_ptr; /* increment the main pointer */

        *current_pos_ptr = skip_whitespace(*current_pos_ptr); /* Skip spaces after a number */
        if (**current_pos_ptr == ',') {
            (*current_pos_ptr)++;
            /* Check if there is an end of line or another comma immediately after this comma */
            temp_ptr = skip_whitespace(*current_pos_ptr);
            if (*temp_ptr == '\0' && count < MAX_NUMBERS_FOR_READ_MAT) {
                 report_error("A comma at the end of a list without a number after it.");
                 *error_flag = true;
                 return false;
            }
            if (*temp_ptr == ',') {
                 report_error("Multiple consecutive commas in the list of numbers.");
                 *error_flag = true;
                 return false;
            }
        } else if (**current_pos_ptr != '\0') { /* No comma or end of line - error */
        	/* This can happen if there are more than 16 numbers, and the 17th is valid. */
        	/* In this case, it is not an error according to the requirements ("the program will ignore the excess values"). */
        	/* The loop will terminate because count < MAX_NUMBERS_FOR_READ_MAT. */
        	/* The final expect_end_of_command test will catch real garbage. */
            break;
        }
    }

    if (count == 0) { /* No number was received */
        report_error("At least one number is required for the read_mat command.");
        *error_flag = true;
        return false;
    }

    set_matrix_values(target_matrix, numbers, count);
    return true;
}

/**
 * Checks that there are no additional characters (other than spaces) at the end of the command.
 */
bool expect_end_of_command(char **current_pos_ptr, bool *error_flag) {
    if (*error_flag) return false;

    *current_pos_ptr = skip_whitespace(*current_pos_ptr);
    if (**current_pos_ptr != '\0') {
        report_error("Text started after the end of the command.");
        *error_flag = true;
        return false;
    }
    return true;
}


/* ---Main Program - main --- */
int main() {
    char line_buffer[MAX_LINE_LEN];
    bool is_running = true;
    int i;
    char *current_pos;
    char command_name[MAX_COMMAND_LEN];
    int cmd_len;
    char *cmd_start;
    bool line_error_occurred;
    mat *m1, *m2, *m3;
    double scalar_value;
    int k;


    /* Reset all matrices at the beginning of the program */
    for (i = 0; i < num_defined_matrices; i++) {
        zero_mat(all_matrices[i]);
    }

    printf("Matrix calculator ready for action.\n");

    while (is_running) {
        printf("\n Enter a command:\n> ");
        fflush(stdout);

        if (fgets(line_buffer, sizeof(line_buffer), stdin) == NULL) {
            if (feof(stdin)) {
                report_error("The end of input was reached without a stop command.");
            } else {
                perror("Error reading input from stdin");
            }
            is_running = false; /* End program */
            continue;
        }

        /* Print the line that was received */
        printf("Command entered: %s", line_buffer);

        current_pos = line_buffer;
        current_pos[strcspn(current_pos, "\n")] = '\0';

        current_pos = skip_whitespace(current_pos);

        if (*current_pos == '\0') {
            continue;
        }

        /* --- analyse command --- */
        cmd_len = 0;
        cmd_start = current_pos;

        while (*current_pos && !isspace((unsigned char)*current_pos) && *current_pos != ',' && cmd_len < MAX_COMMAND_LEN - 1) {
            command_name[cmd_len++] = *current_pos++;
        }
        command_name[cmd_len] = '\0';

        line_error_occurred = false;

        if (cmd_len == 0 && *cmd_start != '\0') {
            report_error("Missing or invalid command name at the beginning of the line.");
            line_error_occurred = true;
        } else if (cmd_len == MAX_COMMAND_LEN - 1 && *current_pos && !isspace((unsigned char)*current_pos) && *current_pos != ',') {
            report_error("Command name too long");
            line_error_occurred = true;
            while (*current_pos && *current_pos != '\n') current_pos++;
        } else {
        	/* Check that the command name is in lowercase (if explicitly required, beyond comparison) */
            for(k=0; command_name[k]; k++){
                if(!(islower((unsigned char)command_name[k]) || command_name[k] == '_')){
                     report_error("Undefined command name (must be lowercase and underscore only).");
                     line_error_occurred = true;
                     break;
                }
            }
        }

        if (line_error_occurred) {
            continue;
        }


        /* --- Execute the command --- */
        m1 = NULL; m2 = NULL; m3 = NULL;

        if (strcmp(command_name, "read_mat") == 0) {
            if (parse_matrix_operand(&current_pos, &m1, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_numbers_list_for_read_mat(&current_pos, m1, &line_error_occurred) &&
                expect_end_of_command(&current_pos, &line_error_occurred)) {
            	/* The command was executed successfully (set_matrix_values ​​was called from parse_numbers_list) */
            }
        } else if (strcmp(command_name, "print_mat") == 0) {
            if (parse_matrix_operand(&current_pos, &m1, &line_error_occurred) &&
                expect_end_of_command(&current_pos, &line_error_occurred)) {
                print_mat_func(m1);
            }
        } else if (strcmp(command_name, "add_mat") == 0) {
            if (parse_matrix_operand(&current_pos, &m1, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m2, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m3, &line_error_occurred) &&
                expect_end_of_command(&current_pos, &line_error_occurred)) {
                add_mat_func(m1, m2, m3);
            }
        } else if (strcmp(command_name, "sub_mat") == 0) {
             if (parse_matrix_operand(&current_pos, &m1, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m2, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m3, &line_error_occurred) &&
                expect_end_of_command(&current_pos, &line_error_occurred)) {
                sub_mat_func(m1, m2, m3);
            }
        } else if (strcmp(command_name, "mul_mat") == 0) {
            if (parse_matrix_operand(&current_pos, &m1, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m2, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m3, &line_error_occurred) &&
                expect_end_of_command(&current_pos, &line_error_occurred)) {
                mul_mat_func(m1, m2, m3);
            }
        } else if (strcmp(command_name, "scalar_mul") == 0) {
            if (parse_matrix_operand(&current_pos, &m1, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_scalar_operand(&current_pos, &scalar_value, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m3, &line_error_occurred) &&
                expect_end_of_command(&current_pos, &line_error_occurred)) {
                scalar_mul_func(m1, scalar_value, m3);
            }
        } else if (strcmp(command_name, "trans_mat") == 0) {
            if (parse_matrix_operand(&current_pos, &m1, &line_error_occurred) &&
                parse_comma_separator(&current_pos, &line_error_occurred) &&
                parse_matrix_operand(&current_pos, &m2, &line_error_occurred) &&
                expect_end_of_command(&current_pos, &line_error_occurred)) {
                trans_mat_func(m1, m2);
            }
        } else if (strcmp(command_name, "stop") == 0) {
            if (expect_end_of_command(&current_pos, &line_error_occurred)) {
                is_running = false;
            }
        } else {
            if(!line_error_occurred) {
                 report_error("Command name not defined.");
            }
        }
        /* If happens == true, the error message has already been printed by one of the parsing functions. */
        /* The program will continue to receive the next command. */
    }

    printf("\nThe program is ending its operation..\n");
    return 0;
}
