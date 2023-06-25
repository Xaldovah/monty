#include "monty.h"

/**
 * sub - This function subtracts the top two elements
 * @stack: The stack
 * @line_number: ...
 * Return: The result.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't sub, stack too short\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
