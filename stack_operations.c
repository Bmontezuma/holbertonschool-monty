#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @n: The value to be pushed.
 */
void push(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}
/**
 * pall - Print all elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number; /* Unused parameter */

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

