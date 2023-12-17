#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 */
void pint(const Node *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Error: can't pint, stack is empty\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", stack->n);
}

