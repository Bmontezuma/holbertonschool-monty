#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * int_to_string - Convert an integer to a string
 * @value: Integer value to be converted
 *
 * Return: Pointer to the resulting string
 */
char *int_to_string(int value)
{
	char *result;
	int length;

	length = snprintf(NULL, 0, "%d", value);
	result = malloc(length + 1);

	if (result == NULL)
	{
	handle_error(MALLOC_ERROR, 0);
	return (NULL);
	}

	snprintf(result, length + 1, "%d", value);
	return (result);
}
