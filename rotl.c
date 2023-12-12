#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the beginning of the stack.
 */
void rotl(stack_t **stack)
{
	stack_t *first, *last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = first;
    
	while (last->next)
	{
		last = last->next;
	}

	last->next = first;
	first->prev = last;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
}
