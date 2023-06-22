#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIFO 1
#define FIFO 0
#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"
#define _POSIX_C_SOURCE 200809L

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
 * struct info_s - Data From The Monty File
 * @type: FIFO LIFO
 */
typedef struct info_s
{
	int format;
	char **arg;
} info_t;

/* Global variables */
extern info_t info;
extern char **op_toks;
char **op_toks = NULL;

char **strtow(char *str, char *delims);
char *get_int(int n);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int execute_script(FILE *script_fd);
int process_opcodes(char *opcode, stack_t **stack);

/* Function prototypes */
void push(stack_t **stack, int value);
void pall(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void pop(stack_t **stack);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, int n);
void free_globals(void);
void free_list(stack_t *stack);
int is_num(char *str);
void add_fifo(stack_t **stack, stack_t *n_node);
void add_lifo(stack_t **stack, stack_t *n_node);
void f_pop(stack_t **head, unsigned int counter);

#endif /* MONTY_H */
