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

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_info();
		free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
