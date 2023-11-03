#include "shell.h"

int main() {
    char *input = NULL;
    char **args;
    int status;

    do {
        printf("$ ");  // Print the prompt
        input = read_line();  // Read the input line
        args = split_line(input);  // Split the line into args
        status = execute(args);  // Execute the command

        free(input);
        free(args);
    } while (status);

    return EXIT_SUCCESS;
}
