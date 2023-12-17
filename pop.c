#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pop - Removes the top node from the stack
 * @stack: Pointer to the top of the stack
 *
 * Return: Value stored in the removed node
 */
int pop(Node **stack)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "Error: stack is empty\n");
		exit(EXIT_FAILURE);
	}

	int value = (*stack)->n;
	Node *temp = *stack;

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);

	return (value);
}
