#include "monty.h"

/**
 * free_list - Frees a stack.
 * @stack: Pointer to the stack to be freed.
 */
void free_list(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * free_info - Frees the global info structure.
 */
void free_info(void)
{
	free(info.arg);
	info.arg = NULL;
}
