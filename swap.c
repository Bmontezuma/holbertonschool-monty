#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printStack(stack);

    swap(&stack, 1);

    printStack(stack);

    return 0;
}

