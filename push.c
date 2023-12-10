#include "monty.h"

/**
 * push - Function to push a node to the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 *
 * Return: Void
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
	handle_error(MALLOC_ERROR, 0);
	return;	
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
