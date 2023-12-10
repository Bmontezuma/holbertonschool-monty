#include "monty.h"

/**
 * pop - remove the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in Monty bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
	monty_error("can't pop an empty stack", line_number);
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		if (*stack)
		(*stack)->prev = NULL;
	}
}
