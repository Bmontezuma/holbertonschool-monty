#include "monty.h"

/**
 * nop - do nothing
 * @stack: double pointer to the head of the stack
 * @line_number: line number in Monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}
