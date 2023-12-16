/* main.c */

#include "monty.h"

/**
 * main - Entry point of the Monty program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    monty_arguments_t args;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file.m>\n", argv[0]);
        return EXIT_FAILURE;
    }

    args = initialize_arguments(argc, argv);
    validate_arguments(args);

    /* Open and read the Monty bytecode file */
    FILE *bytecode_file = open_bytecode_file(args.filename);
    while ((read = getline(&line, &len, bytecode_file)) != -1)
    {
        char **tokens = tokenize_line(line);
        if (tokens != NULL && tokens[0] != NULL)
        {
            run_instructions(tokens, &stack);
            free_tokens(tokens);
        }
    }

    /* Free resources */
    free_args_tokens_stack(argc, argv, NULL, &stack);
    free(line);
    close_bytecode_file(bytecode_file);

    return EXIT_SUCCESS;
}

