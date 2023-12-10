#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Prints the value at top of stack
 * @stack: Pointer to the top of stack
 * @line_number: Line number in Monty byte code file
 *
 * This function prints value at top of the stack followed by newline.
 * If the stack is empty, it prints error message and exits with EXIT_FAILURE.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
