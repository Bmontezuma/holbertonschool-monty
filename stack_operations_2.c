#include "monty.h"

/**
 * pint - Print the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Remove the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}

/**
 * nop - Do nothing.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    /* Do nothing */
}

/**
 * swap - Swap the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
