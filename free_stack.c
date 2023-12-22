#include "monty.h"

/**
 * freeStack - Frees a stack.
 * @stack: Pointer to the top of the stack
 */
void freeStack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}

