#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * queue - Sets the format of the data to a queue (FIFO)
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
