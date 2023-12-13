#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
