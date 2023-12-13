#include "monty.h"

/**
 * execute_opcode - Execute the appropriate opcode function based on the command.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void execute_opcode(stack_t **stack, unsigned int line_number)
{
    instruction_t op_codes[] = {
        {"push", op_push},
        {"pall", op_pall},
        {"pint", op_pint},
        {"pop", op_pop},
        {"swap", op_swap},
        {"add", op_add},
        {"sub", op_sub},
        {"div", op_div},
        {"mul", op_mul},
        {"mod", op_mod},
        {"pchar", op_pchar},
        {NULL, NULL}
    };

    char *current_opcode = arguments.command;

    for (int i = 0; op_codes[i].opcode; i++)
    {
        if (strcmp(current_opcode, op_codes[i].opcode) == 0)
        {
            op_codes[i].f(stack, line_number);
            return;
        }
    }

    print_error_and_exit(OPCODE_ERROR, current_opcode, line_number);
}

/**
 * is_valid_integer - Check if a string represents a valid integer.
 * @str: String to verify.
 * Return: 1 if it is a digit, 0 otherwise.
 */
int is_valid_integer(char *str)
{
    if (!str || *str == '\0')
        return 0;

    if (*str == '-')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

/**
 * get_stack_length - Calculate the length of the stack.
 * @stack: Pointer to the head of the stack.
 * Return: Length of the stack.
 */
int get_stack_length(stack_t *stack)
{
    int count = 0;
    stack_t *current = stack;

    while (current)
    {
        count++;
        current = current->next;
    }

    return count;
}

int main(int argc, char **argv)
{
    char *line = NULL;
    size_t len = 0;
    FILE *file;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
        print_error_and_exit(USAGE_ERROR, NULL, 0);

    file = fopen(argv[1], "r");
    if (!file)
        print_error_and_exit(FILE_ERROR, argv[1], 0);

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        if (*line == '\n' || *line == '#')
            continue;

        arguments.command = strtok(line, "\n ");
        if (!arguments.command || strcmp(arguments.command, "nop") == 0)
            continue;

        arguments.value = strtok(NULL, "\n ");
        execute_opcode(&stack, line_number);
    }

    free_resources(line, stack);
    fclose(file);
    return 0;
}

