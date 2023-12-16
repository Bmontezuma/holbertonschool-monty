/* monty.h */

#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
 * struct arg_s - hold variables
 * @stream: File that connects to the stream from file
 * @line: string which will be the line of text read from stream
 *
 * Description: holds variables that will be used
 * in different functions of project as well as variables
 * that will require memory allocation and freeing
 */

/* Structure for Monty program arguments */
typedef struct monty_arguments_s
{
    char *filename;
    char **instructions;
} monty_arguments_t;

/* Function prototypes for operations.c */
void add(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void subtract(stack_t **stack, unsigned int line_number);
/* Function prototypes for stream_operations.c */
FILE *open_bytecode_file(const char *filename);
void close_bytecode_file(FILE *stream);
/* Function prototype for free_memory.c */
void free_args_tokens_stack(int argc, char **argv, char **tokens, stack_t **stack);
/* Function prototypes for arguments.c */
monty_arguments_t initialize_arguments(int argc, char *argv[]);
void validate_arguments(monty_arguments_t args);
/* Function prototype for is_number.c */
int is_number(const char *str);
/* Function prototypes for stack_operations_2.c */
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
/* Function prototypes for stack_operations_2.c */
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
/* Function prototypes for stack_operations_3.c */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
/* Function prototypes for stack_queue.c */
void switch_mode(stack_t **stack, unsigned int line_number, int mode);
char **tokenize_line(char *line);
void free_queue(stack_t **stack);
/* Function prototypes for stream_operations.c */
char **get_instructions(const char *filename);
/* Function prototype for stack_operations.c */
void free_stack(stack_t **stack);
void push(stack_t **stack, int n);
void pall(stack_t **stack, unsigned int line_number);
/* Function prototypes for interpreter.c */
void run_instructions(char **instructions, stack_t **stack);
void free_tokens(char **tokens);
void execute_instruction(char *instruction, stack_t **stack);
#endif /* MONTY_H */

