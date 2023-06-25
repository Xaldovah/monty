#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being executed
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pchar, stack empty\n");
		free_info();
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L<line_number>: can't pchar, value out of range\n");
		free_info();
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
