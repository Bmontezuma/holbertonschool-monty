#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Removes top element of stack
 * @stack: Pointer to the top o stack
 * @line_number: Line number in the Monty byte code file
 *
 * This removes the top element of the stack.
 * If the stack is empty, it prints error message and exits with EXIT_FAILURE.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
