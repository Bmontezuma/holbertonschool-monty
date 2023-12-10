#include "monty.h"

/**
 * swap - swap the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		monty_error("can't swap, stack too short", line_number);
	}
	else
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
