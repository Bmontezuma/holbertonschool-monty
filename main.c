#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * execute_monty - Execute the Monty interpreter logic
 * @filename: Name of the Monty bytecode file
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int execute_monty(const char *filename)
{
	Node *stack = NULL;

	if (process_instructions(filename, &stack) == EXIT_FAILURE)
	{
		fprintf(stderr, "Error: Failed to process Monty bytecode\n");
		cleanup(stack); // Cleanup on failure
		return (EXIT_FAILURE);
	}

	cleanup(stack); // Cleanup before exiting

	return (EXIT_SUCCESS);
}

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
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	char *filename = argv[1];

	int result = execute_monty(filename);

	if (result == EXIT_FAILURE)
	{
		fprintf(stderr, "Error: Monty execution failed\n");
	}

	return (result);
}

