#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in Monty byte code file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
