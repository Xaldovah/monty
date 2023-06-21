#include "monty.h"

/**
 * _stack - Set the format to the data to a stack 
 * @stack: pointer to head
 * @line_number: ...
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	info.format = LIFO;
}

/**
 * _queue - Set the format to the data to a queue
 * @stack: pointer to head
 * @line_number: ...
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	info.format = FIFO;
}
