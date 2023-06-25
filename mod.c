#include "monty.h"

/**
 * mod - This function computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stack: The stack
 * @line_number: ...
 * Return:
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == 0)
	{
		fprintf(stderr, "L<line_number>: division by zero\n");
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
