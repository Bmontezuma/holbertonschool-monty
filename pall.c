#include "monty.h"
#include <stdio.h>
/**
 * pall - Prints all the values in the stack from the top.
 * @stack: Double pointer to the head of the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
