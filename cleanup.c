#include "monty.h"
#include <stdlib.h>

/**
 * cleanup - Frees the memory occupied by the stack
 * @stack: Pointer to the top of the stack
 */
void cleanup(Node *stack)
{
    Node *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
