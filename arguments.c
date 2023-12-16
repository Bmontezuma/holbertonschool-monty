#include "monty.h"

/**
 * initialize_arguments - Initialize the arguments for the Monty program.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Return: A structure containing the initialized arguments.
 */
monty_arguments_t initialize_arguments(int argc, char *argv[])
{
	monty_arguments_t args;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file.m>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	args.filename = argv[1];
	args.instructions = get_instructions(args.filename);

	return args;
}

/**
 * validate_arguments - Validate the arguments for the Monty program.
 * @args: The structure containing the initialized arguments.
 */
void validate_arguments(monty_arguments_t args)
{
	if (args.instructions == NULL)
	{
		fprintf(stderr, "Error: Unable to read instructions from file %s\n", args.filename);
		exit(EXIT_FAILURE);
	}
}
