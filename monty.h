#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Node - Represents a node in the stack
 * @n: Value stored in the node
 * @prev: Pointer to the previous node in the stack
 * @next: Pointer to the next node in the stack
 */
typedef struct Node
{
	int n;
	struct Node *prev;
	struct Node *next;
} Node;

/**
 * cleanup - Frees the memory occupied by the stack
 * @stack: Pointer to the top of the stack
 */
void cleanup(stack_t **stack);

/* Function prototypes */
void *safe_malloc(size_t size);
void free_stack(Node *stack);
void nop(const void *stack);
void pall(const Node *stack);
void pint(const Node *stack);
int pop(Node **stack);
Node *push(Node *stack, int value);
void swap_int(int *a, int *b);
int process_instructions(const char *filename, Node **stack);
int is_numeric(const char *str, int *value);
#endif /* MONTY_H */

