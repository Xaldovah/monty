#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void) line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
