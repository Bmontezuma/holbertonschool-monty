#include "monty.h"

/**
 * sub - Function to subtract top element from second top element of stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 *
 * Return: Void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(STACK_TOO_SHORT, line_number);
		return;
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * monty_div - Function to divide second top element by top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 *
 * Return: Void
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		handle_error(DIVIDE_BY_ZERO, line_number);
		return;
	}

		(*stack)->next->n /= (*stack)->n;
		pop(stack, line_number);
}

/**
 * mul - Function to multiply the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 *
 * Return: Void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(STACK_TOO_SHORT, line_number);
		return;
	}

		(*stack)->next->n *= (*stack)->n;
		pop(stack, line_number);
}

/**
 * mod - Function to compute the rest of the division of the second top element
 * by the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the Monty file
 *
 * Return: Void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL || (*stack)->n == 0)
	{
		handle_error(DIVIDE_BY_ZERO, line_number);
		return;
	}

		(*stack)->next->n %= (*stack)->n;
		pop(stack, line_number);
}
