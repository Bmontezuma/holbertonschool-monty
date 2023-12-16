/* stack_queue.c */

#include "monty.h"

/**
 * switch_mode - Switch between stack and queue modes.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 * @mode: The mode to switch to (0 for stack, 1 for queue).
 */
void switch_mode(stack_t **stack, unsigned int line_number, int mode)
{
    (void)line_number;
    (void)mode;

    /* You can implement this function based on your specific needs */
    /* For example, you can set a global variable to indicate the mode */
    /* or you can modify the stack structure accordingly */
}

/**
 * tokenize_line - Tokenize a line of input.
 * @line: The line to tokenize.
 * Return: An array of strings containing the tokens.
 */
char **tokenize_line(char *line)
{
    char **tokens = NULL;
    char *token;
    size_t i = 0;

    token = strtok(line, " \t\n");
    while (token != NULL)
    {
        tokens = realloc(tokens, (i + 1) * sizeof(char *));
        if (tokens == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }

        tokens[i] = strdup(token);
        if (tokens[i] == NULL)
        {
            fprintf(stderr, "Error: strdup failed\n");
            exit(EXIT_FAILURE);
        }

        i++;
        token = strtok(NULL, " \t\n");
    }

    return tokens;
}

/**
 * free_queue - Free the memory used by a queue.
 * @stack: A pointer to the stack.
 */
void free_queue(stack_t **stack)
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
    }
}

