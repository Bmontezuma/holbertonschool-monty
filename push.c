#include "monty.h"

void opcode_push(stack_t **stack, unsigned int line_number, char *value_str)
{
	int value;
    
	if (!value_str)
	{
		handle_error(UNKNOWN_INSTRUCTION_ERROR, line_number);
	}

	value = atoi(value_str);

	push(stack, value);
}
