#include "monty.h"

/**
 * add - Add the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 * Return: Void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */
	if (*stack && (*stack)->next)
	{
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
	}
	else
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
}

/**
 * divide - Divide the second top element of the stack by the top element.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 * Return: Void.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */
	if (*stack && (*stack)->next)
	{
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
	}
	else
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
}

/**
 * mod - Compute the modulus of the second top element by the top element.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 * Return: Void.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */
	if (*stack && (*stack)->next)
	{
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * multiply - Multiply the second top element of the stack with the top element.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 * Return: Void.
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */
	if (*stack && (*stack)->next)
	{
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
	}
	else
	{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
    }
}

/**
 * subtract - Subtract the top element of the stack from the second top element.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 * Return: Void.
 */
void subtract(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* Unused parameter */
	if (*stack && (*stack)->next)
	{
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
	}
	else
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
}
