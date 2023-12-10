#include "monty.h"

/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the beginning of the stack.
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
