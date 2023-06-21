#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;
	int n;
	n_node = malloc(sizeof(stack_t));

	if (n_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if (!info.arg || !is_num(*info.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(n_node);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(*info.arg);
	n_node->n = n;
	if (info.format == LIFO)
	{
		add_lifo(stack, n_node);
	}
	else if (info.format == FIFO)
	{
		add_fifo(stack, n_node);
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
