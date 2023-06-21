#include "monty.h"

/**
 * add_lifo - add node with lifo
 * @stack: head of stack
 * @n_node: the node to add
 */
void add_lifo(stack_t **stack, stack_t *n_node)
{
	if (*stack == NULL)
	{
		*stack = n_node;
	}
	else
	{
		n_node->next = *stack;
		(*stack)->prev = n_node;
		*stack = n_node;
	}
}

/**
 * add_fifo - add node with fifo
 * @stack: head of stack
 * @n_node: the node to add
 */
void add_fifo(stack_t **stack, stack_t *n_node)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		*stack = n_node;
	}
	else
	{
		temp = *stack;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n_node;
		n_node->prev = temp;
	}
}
