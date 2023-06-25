#include "monty.h"

/**
 * _div - This func divides the top two elements
 * @stack: The stack
 * @line_number: ...
 * Return: ...
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't div, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L<line_number>: division by zero\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
