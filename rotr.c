#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = *stack;
		(*stack)->prev = last;
		last->prev->next = NULL;
		last->prev = NULL;
		*stack = last;
	}
}
