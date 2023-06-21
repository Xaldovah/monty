#include "monty.h"

/**
 * free_list - free any mem allocated
 * @stack: Either stack or queue
 */
void free_list(stack_t *stack)
{
	stack_t *node;

	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

/**
 * free_globals - free any data that was allocated
 *
 *
 */
void free_info(void)
{
	free(info.arg);
	info.arg = NULL;
}
