#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Pushes a new node onto the stack
 * @stack: Pointer to the top of the stack
 * @value: Value to be stored in the new node
 *
 * Return: Pointer to the new top of the stack
 */
Node *push(Node *stack, int value)
{
	Node *new_node = malloc(sizeof(Node));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = stack;

	if (stack != NULL)
	stack->prev = new_node;

	return (new_node);
}

/**
 * is_integer - Checks if a string is a valid integer
 * @str: String to check
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;

	while (str[i] != '\0')
	{
	if (str[i] < '0' || str[i] > '9')
		return (0);
	i++;
	}

	return (1);
}

/**
 * push_handler - Handles the push command, ensuring correct usage
 * @stack: Pointer to the top of the stack
 * @value: String representing the value to be pushed
 * @line_number: Line number in the Monty script
 */
void push_handler(Node **stack, const char *value, unsigned int line_number)
{
    if (!is_integer(value))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        return;
    }

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(value);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
