#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define DELIMS " \n\t\a"
#define MAX_LINE_LENGTH 100
#define LIFO 1
#define FIFO 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

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
	FILE *fon;
	char *line;
	char *filename;
	int format;
	char **arg;
	int line_number;
} info_t;

/* Global variables */
extern info_t info;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, int n);
void free_info(void);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void parse_line(char *line, stack_t **stack, unsigned int line_number);
void free_list(stack_t *stack);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
int is_num(char *str);
int p_init(stack_t **stack);
int _isdigit(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_populate(void *i, int elem, unsigned int len);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
int _token(void);
void add_fifo(stack_t **stack, stack_t *n_node);
void add_lifo(stack_t **stack, stack_t *n_node);

#endif /* MONTY_H */
