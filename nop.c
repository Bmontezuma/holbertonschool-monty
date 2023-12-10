#include "monty.h"
#include <stdio.h>

/**
 * nop - Doesn't do anything
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * This function doesn't perform any operation.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This function does nothing (nop) */
}
