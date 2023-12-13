#include "monty.h"

/**
 * main - Entry point, file parsing.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    FILE *file;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
        print_error_and_exit(USAGE_ERROR, NULL, 0);

    file = fopen(argv[1], "r");
    if (!file)
        print_error_and_exit(FILE_ERROR, argv[1], 0);

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        if (*line == '\n' || *line == '#')
            continue;

        arguments.command = strtok(line, "\n ");
        if (!arguments.command || strcmp(arguments.command, "nop") == 0)
            continue;

        arguments.value = strtok(NULL, "\n ");
        execute_opcode(&stack, line_number);
    }

    free_resources(line, stack);
    fclose(file);
    return 0;
}

