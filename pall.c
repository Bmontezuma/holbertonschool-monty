// pall.c

#include "monty.h"

/**
 * pall - Prints all values on the stack
 * @stack: Pointer to the top of the stack
 *
 * Description: Prints all the values on the stack, starting from the top.
 * Format: see example
 * If the stack is empty, don’t print anything
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

