/* stack_operations_3.c */

#include "monty.h"

/**
 * pchar - Print the character at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}

/**
 * pstr - Print the string starting at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
    {
        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}

/**
 * rotl - Rotate the stack to the top.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        temp = *stack;
        last = *stack;

        while (last->next != NULL)
            last = last->next;

        *stack = (*stack)->next;
        (*stack)->prev = NULL;

        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
    }
}

/**
 * rotr - Rotate the stack to the bottom.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *first;

    (void)line_number;

    if (*stack != NULL && (*stack)->next != NULL)
    {
        temp = *stack;
        first = *stack;

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;

        *stack = temp;
    }
}

