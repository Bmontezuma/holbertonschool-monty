#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - Adds top two elements of the stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * This adds the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message
 * and exits with EXIT_FAILURE.
 * The result is stored in the second top element of the stack,
 * and the top element is removed.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
