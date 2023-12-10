#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in Monty bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
	monty_error("can't pint, stack empty", line_number);
	}
	else
	{
	printf("%d\n", (*stack)->n);
	}
}
