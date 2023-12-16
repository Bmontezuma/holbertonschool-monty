/* free_memory.c */

#include "monty.h"

/**
 * free_args_tokens_stack - Free memory for arguments, tokens, and the stack.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * @tokens: The array of tokens.
 * @stack: A pointer to the stack.
 */
void free_args_tokens_stack(int argc, char **argv, char **tokens, stack_t **stack)
{
	int i;

	/* Free arguments */
	for (i = 0; i < argc; i++)
	{
		free(argv[i]);
	}
	free(argv);

	/* Free tokens */
	if (tokens != NULL)
	{
		for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
	}

	/* Free the stack */
	free_stack(stack);
}
/**
 * free_stack - Free the memory used by a stack.
 * @stack: A pointer to the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *current, *temp;

    if (*stack != NULL)
    {
        current = *stack;
        while (current != NULL)
        {
            temp = current;
            current = current->next;
            free(temp);
        }
        *stack = NULL; /* Set the stack pointer to NULL after freeing all nodes */
    }
}
