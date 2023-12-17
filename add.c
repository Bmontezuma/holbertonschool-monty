#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in Monty byte code file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
