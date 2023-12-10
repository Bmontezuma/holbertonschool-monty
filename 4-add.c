#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in Monty bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		monty_error("can't add, stack too short", line_number);
	}
	else
	{
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
	}
}
