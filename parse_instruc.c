#include "monty.h"
#include <stdlib.h>
#include <string.h>

void push_wrapper(stack_t **stack, unsigned int line_number, int value)
{
    push(stack, line_number, value);
}

int parse_instruction(char *line, instruction_t *instruction)
{
    char *opcode = strtok(line, " \t\n");
    char *arg = strtok(NULL, " \t\n");

    if (!opcode)
        return (-1); /* No opcode found */

    /* Trim trailing spaces from the opcode */
    size_t len = strlen(opcode);
    while (len > 0 && (opcode[len - 1] == ' ' || opcode[len - 1] == '\t'))
    {
        opcode[len - 1] = '\0';
        len--;
    }

    /* Fill instruction_t structure based on the opcode */
    if (strcmp(opcode, "push") == 0)
    {
        if (!arg)
            return (-1); /* Missing argument for push */

        /* Check if the argument is a valid integer */
        char *endptr;
        int value = strtol(arg, &endptr, 10);

        if (*endptr != '\0')
            return (-1); /* Invalid integer */

        instruction->opcode = strdup(opcode);
        instruction->f = push_wrapper;
        instruction->argument = value;
        return (0); /* success */
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        /* Fill instruction_t structure for pall */
        instruction->opcode = strdup(opcode);
        instruction->f = pall; // Assuming you have a pall function
        return (0); /* success */
    }

    /* Handle other opcodes as needed */

    return (-1); /* Unknown opcode */
}

