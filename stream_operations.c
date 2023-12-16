#include "monty.h"

/**
 * open_bytecode_file - Open a Monty bytecode file for reading.
 * @filename: The name of the Monty bytecode file to open.
 * Return: A pointer to the opened stream.
 */
FILE *open_bytecode_file(const char *filename)
{
	FILE *stream = fopen(filename, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return stream;
}

/**
 * close_bytecode_file - Close a previously opened Monty bytecode file.
 * @stream: A pointer to the stream to close.
 */
void close_bytecode_file(FILE *stream)
{
	if (fclose(stream) != 0)
	{
		fprintf(stderr, "Error: Can't close the file\n");
		exit(EXIT_FAILURE);
	}
}
