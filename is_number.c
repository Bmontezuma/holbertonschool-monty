#include "monty.h"

/**
 * is_number - Checks if a given string is a number
 * @str: The string to check
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
	return (0);

	if (*str == '-')
		str++;

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }

    return (1);
}
