#include "monty.h"

/**
 * mul - This func multiplies the top two elements
 * @stack: the stack
 * @line_number: ...
 * Return: ...
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't mul, stack too\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
