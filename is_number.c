/* is_number.c */

#include "monty.h"

/**
 * is_number - Check if a string is a valid number.
 * @str: The string to check.
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	/* Handle negative numbers */
	if (*str == '-')
		str++;

	/* Check if the remaining characters are digits */
	while (*str != '\0')
	{
	if (!isdigit(*str))
		return 0;
	str++;
	}

	return (1);
}
