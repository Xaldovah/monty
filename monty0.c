#include "monty.h"

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @value: current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t** stack, unsigned int value)
{
stack_t* tmp, * new_node;
int i;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
	fprintf(stderr, "Error: Failed to allocate memory\n");
	exit(EXIT_FAILURE);
}
if (op_toks[1] == NULL)
{
	fprintf(stderr, "Error: Usage: push integer\n");
	exit(EXIT_FAILURE);
}
for (i = 0; op_toks[1][i]; i++)
{
	if (op_toks[1][i] == '-' && i == 0)
		continue;
	if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
	{
		fprintf(stderr, "Error: Invalid integer argument\n");
		exit(EXIT_FAILURE);
	}
}
new_node->n = atoi(op_toks[1]);

if (check_mode(*stack) == STACK)
{
	tmp = (*stack)->next;
	new_node->prev = *stack;
	new_node->next = tmp;
	if (tmp)
		tmp->prev = new_node;
	(*stack)->next = new_node;
}
else
{
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	new_node->prev = tmp;
	new_node->next = NULL;
	tmp->next = new_node;
}
}

/**
 * monty_pall - Prints values of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @value: current working line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int value)
{
	stack_t* tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
