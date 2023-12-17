#include "monty.h"

/**
 * cleanup - Frees the memory occupied by the stack
 * @stack: Double pointer to the top of the stack
 */
void cleanup(stack_t **stack)
{
    while (*stack)
    {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

