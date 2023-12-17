#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
