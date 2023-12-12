#include "monty.h"
#include <ctype.h>
/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the stack.
 * @monty_data: A pointer to the Monty data structure.
 * @line_number: The line number in the Monty byte code file.
 */
void push(stack_t **stack, monty_t *monty_data, unsigned int line_number)
{
    int value;

    if (!monty_data->token || !is_number(monty_data->token))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(monty_data->token);
    push_stack(stack, value);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty script.
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
 * is_number - Checks if a string represents a valid integer.
 * @str: String to be checked.
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(char *str)
{
	if (!str)
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
	if (!isdigit(*str))
		return (0);
	str++;
	}

	return (1);
}

