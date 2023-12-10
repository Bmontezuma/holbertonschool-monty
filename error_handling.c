#include "monty.h"
#include <stdio.h>

void handle_error(ErrorType error_type, unsigned int line_number)
{
	switch (error_type)
	{
	case FILE_OPEN_ERROR:
		fprintf(stderr, "Error: Can't open file\n");
		break;
	case UNKNOWN_INSTRUCTION_ERROR:
		fprintf(stderr, "L%u: unknown instruction\n", line_number);
        	break;
	case MALLOC_ERROR:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	default:
		fprintf(stderr, "Unknown error\n");
	}
	exit(EXIT_FAILURE);
}
