#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * tokenize - Tokenizes a line from the Monty bytecode file
 * @line: Line to be tokenized
 *
 * Return: Array of tokens (strings)
 */
char **tokenize(char *line)
{
	const char delimiters[] = " \t\n";
	char **tokens = NULL;
	char *token = strtok(line, delimiters);
	int token_count = 0;

	while (token != NULL)
	{
		tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
	if (tokens == NULL)
	{
		perror("Failed to allocate memory for tokens");
		exit(EXIT_FAILURE);
	}

	tokens[token_count] = strdup(token);
	if (tokens[token_count] == NULL)
	{
		perror("Failed to duplicate token");
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, delimiters);
	token_count++;
	}

	tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
	if (tokens == NULL)
	{
	perror("Failed to allocate memory for tokens");
	exit(EXIT_FAILURE);
	}
	tokens[token_count] = NULL;

	return (tokens);
}

/**
 * free_tokens - Frees memory allocated for tokens
 * @tokens: Array of tokens to be freed
 */
void free_tokens(char **tokens)
{
	for (int i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
