#include "monty.h"

/**
 * monty_error - print error message and exit with EXIT_FAILURE
 * @message: error message to print
 * @line_number: line number in Monty bytecode file
 */
void monty_error(char *message, unsigned int line_number)
{
	fprintf(stderr, "L%u: %s\n", line_number, message);
	exit(EXIT_FAILURE);
}

