#include "monty.h"

/**
 * add - Function to add the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 *
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(STACK_TOO_SHORT, line_number);
		return;
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
