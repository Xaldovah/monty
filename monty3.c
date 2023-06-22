#include "monty.h"

/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 *
 */
void swap(stack_t **stack)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - Adds top two values of a stack_t linked list.
 * @stack: A pointer to top mode node of a stack_t linked list.
 * Description: result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void add(stack_t **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack);
}
