#include <stdlib.h>
#include "monty.h"

/**
 * _div - This func divides the top two elements
 * @stack: The stack
 * @line_number: ...
 * Return: ...
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't div, stack too short\n");
		free_info();
		free(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
