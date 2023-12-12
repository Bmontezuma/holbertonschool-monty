#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    monty_t monty_data;
    monty_data.file = file;
    monty_data.line_number = 0;
    monty_data.token = NULL;

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, file)) != -1)
    {
        monty_data.line_number++;
        monty_data.token = strtok(line, " \t\n");

        if (monty_data.token == NULL || monty_data.token[0] == '#')
            continue;

        /* Implement logic to call the appropriate function based on the command */
        if (strcmp(monty_data.token, "push") == 0)
        {
            /* Call the push function */
            push(&stack, &monty_data, monty_data.line_number);
        }
        else if (strcmp(monty_data.token, "pop") == 0)
        {
            /* Call the pop function */
            pop(&stack, monty_data.line_number);
        }
        // Add more cases for other commands

        /* Reset token for the next iteration */
        monty_data.token = NULL;
    }

    /* Free allocated resources and close the file */
    fclose(file);
    free(line);
    free_stack(&stack);
    return EXIT_SUCCESS;
}

