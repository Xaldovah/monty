#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	if (_isdigit(info.arg[1]) > 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(info.arg[1]);
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
	}
	*stack = new_node;
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
