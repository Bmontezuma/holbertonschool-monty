#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pall - Prints all the values in the stack
 * @stack: Pointer to the top of the stack
 */
void pall(const Node *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}
