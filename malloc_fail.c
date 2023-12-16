/* malloc_fail.c */

#include "monty.h"

/**
 * malloc_fail - Handle failure in memory allocation.
 */
void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
