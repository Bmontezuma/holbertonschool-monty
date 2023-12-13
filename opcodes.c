#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void push(stack_t **stack, int line_number, int value)	
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (value)
    {
        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack)
            (*stack)->prev = new_node;

        *stack = new_node;
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty byte code file (unused).
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty byte code file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    temp->prev = NULL;
    (*stack)->prev = temp;

    if ((*stack)->next)
        (*stack)->next->prev = *stack;

    *stack = temp;
}
