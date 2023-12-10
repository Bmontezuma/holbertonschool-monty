#include "monty.h"

int main(int argc, char *argv[])
{
	/* Check for the number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* Open the file */
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        	return (EXIT_FAILURE);
	}

	/* Close the file */
	fclose(file);

	return (EXIT_SUCCESS);
}

