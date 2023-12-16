#include "monty.h"

/**
 * get_instructions - Read and parse instructions from a Monty bytecode file.
 * @filename: The name of the Monty bytecode file.
 * Return: An array of strings containing the instructions.
 */
char **get_instructions(const char *filename)
{
    FILE *file = open_bytecode_file(filename);
    char **instructions = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1)
    {
        /* Tokenize the line and store the instructions */
        /* Assuming whitespace is the delimiter, adjust as needed */
        char *token;
        size_t i = 0;

        token = strtok(line, " \t\n");
        while (token != NULL)
        {
            instructions = realloc(instructions, (i + 1) * sizeof(char *));
            if (instructions == NULL)
            {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
            }

            instructions[i] = strdup(token);
            if (instructions[i] == NULL)
            {
                fprintf(stderr, "Error: strdup failed\n");
                exit(EXIT_FAILURE);
            }

            i++;
            token = strtok(NULL, " \t\n");
        }
    }

    free(line);
    close_bytecode_file(file);
    return instructions;
}

/**
 * run_instructions - Execute the instructions obtained from a Monty file.
 * @instructions: An array of strings containing the instructions.
 * @stack: A pointer to the stack.
 */
void run_instructions(char **instructions, stack_t **stack)
{
    size_t i = 0;

    while (instructions[i] != NULL)
    {
        execute_instruction(instructions[i], stack);
        i++;
    }

    /* Free memory allocated for instructions */
    free_tokens(instructions);
}

/**
 * execute_instruction - Execute a single instruction.
 * @instruction: The instruction to execute.
 * @stack: A pointer to the stack.
 */
void execute_instruction(char *instruction, stack_t **stack)
{
    /* Add logic here to execute each specific instruction */
    if (strcmp(instruction, "push") == 0)
    {
        /* Assuming next token after "push" is the integer value */
        int value = atoi(instruction);
        push(stack,value);
    }
    else if (strcmp(instruction, "pall") == 0)
    {
        pall(stack, 0);
    }
    /* Add more conditions for other instructions as needed */
}

/**
 * free_tokens - Free memory allocated for an array of strings.
 * @tokens: An array of strings.
 */
void free_tokens(char **tokens)
{
    size_t i;

    if (tokens != NULL)
    {
        for (i = 0; tokens[i] != NULL; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
    }
}
