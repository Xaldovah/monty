#include "monty.h"

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: pointer to the top mode node of a stack_t linked list.
 * @value: current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int value)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(value));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}
