#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int process_instructions(const char *filename, Node **stack)
{
	(void)stack;

	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	fclose(file);
	return (EXIT_SUCCESS);
}

