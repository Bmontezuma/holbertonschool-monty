#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom. The last element becomes the first.
 * @stack: Double pointer to the head of the stack.
 */
void rotr(stack_t **stack)
{
	if (*stack && (*stack)->next)
	{
		stack_t *last = *stack;
		stack_t *second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

		second_last->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
