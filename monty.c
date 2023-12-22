#include "monty.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        if (opcode && opcode[0] != '#')
        {
            int value = 0;
            if (strcmp(opcode, "push") == 0)
            {
                char *arg = strtok(NULL, " \t\n");
                if (arg)
                    value = atoi(arg);
                else
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    free_stack(&stack);
                    free(line);
                    fclose(file);
                    return (EXIT_FAILURE);
                }
            }

            int i;
            instruction_t instructions[] = {
                {"push", push},
                {"pall", pall},
                {"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
                {NULL, NULL}};

            for (i = 0; instructions[i].opcode; i++)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(&stack, line_number);
                    break;
                }
            }

            if (!instructions[i].opcode)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                free_stack(&stack);
                free(line);
                fclose(file);
                return (EXIT_FAILURE);
            }
        }
    }

    free_stack(&stack);
    free(line);
    fclose(file);

    return (EXIT_SUCCESS);
}

