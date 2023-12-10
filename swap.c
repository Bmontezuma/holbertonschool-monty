#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps top two elements of the stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * This swaps the top two elements of the stack.
 * If the stack contains less than two elements, it prints an error message
 * and exits with EXIT_FAILURE.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
		int temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
}
