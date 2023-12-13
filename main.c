#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	FILE *monty_file;
	char *file_path;
	size_t len = 0;
	ssize_t read;
	char *line = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_path = argv[1];
	monty_file = fopen(file_path, "r");

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
 		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, monty_file)) != -1)
	{
	line_number++;
	if (parse_instruction(line, &instruction))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction.opcode);
		free(line);
		fclose(monty_file);
		free_stack(&stack);
    exit(EXIT_FAILURE);
        }

        instruction.f(&stack, line_number);
    }

    free(line);
    fclose(monty_file);

    return 0;
}

