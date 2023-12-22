#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, int value, unsigned int line_number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
    (void)line_number; // Unused for now
}

void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number; // Unused for now

    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack)
        printf("%d\n", (*stack)->n);
    else
    {
        fprintf(stderr, "L%d: can't pint

