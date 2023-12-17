#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * safe_malloc - Allocates memory and checks for allocation success
 * @size: Size of the memory to allocate
 *
 * Return: Pointer to the allocated memory
 */
void *safe_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	return (ptr);
}

/**
 * free_stack - Frees the memory occupied by the stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(Node *stack)
{
	Node *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
