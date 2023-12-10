#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
FILE *file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

stack_t *stack = NULL;
char *line = NULL;
size_t line_len = 0;
unsigned int line_number = 0;

while (getline(&line, &line_len, file) != -1)
{
line_number++;
}
free(line);
fclose(file);
free_stack(&stack);

return (EXIT_SUCCESS);
}
