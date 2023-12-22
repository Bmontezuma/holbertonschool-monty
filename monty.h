// monty.h

#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Struct for stack node */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

void printStack(stack_t *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}

/* Function prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void printStack(stack_t *stack); // Add this line
void swap(stack_t **stack, unsigned int line_number); // Add this line

#endif /* MONTY_H */

