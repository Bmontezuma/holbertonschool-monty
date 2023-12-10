#include "monty.h"
#include <stdio.h>

/**
 * opcode_pall - Prints all the elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * Description: This function prints all the elements of the stack.
 * It takes the stack and line number as parameters.
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (*stack == NULL)
    {
        fprintf(stderr, "Stack is empty at line %u\n", line_number);
        return;
    }

    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
