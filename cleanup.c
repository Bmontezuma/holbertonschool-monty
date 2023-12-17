#include "monty.h"
#include <stdlib.h>

void cleanup(Node *stack)
{
    while (stack != NULL)
    {
        Node *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

