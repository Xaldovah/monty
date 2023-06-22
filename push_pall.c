#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int n;

	if (info.arg == NULL || !is_num(*info.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(*info.arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (info.format == LIFO)
	{
		add_lifo(stack, new_node);
	}
	else if (info.format == FIFO)
	{
		add_fifo(stack, new_node);
	}
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
