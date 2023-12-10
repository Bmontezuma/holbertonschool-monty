#include "monty.h"

/* Function declarations */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number);
void free_stack(stack_t *stack);

/**
 * main - Monty Byte Code Interpreter
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        execute_opcode(&stack, line, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);

    return EXIT_SUCCESS;
}

