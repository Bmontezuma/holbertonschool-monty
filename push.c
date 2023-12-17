#include "monty.h"
/**
 * push - Pushes a new node onto the stack
 * @stack: Pointer to the top of the stack
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new top of the stack
 */
Node *push(Node *stack, int value)
{
	Node *new_node = malloc(sizeof(Node));

	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = stack;

	if (stack != NULL)
		stack->prev = new_node;

	return (new_node);
}
