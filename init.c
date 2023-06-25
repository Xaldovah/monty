#include "monty.h"
/**
 * p_init - process and parse line
 * @stack: stack
 *
 * Return: 1
 */
int p_init(stack_t **stack)
{
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};
	int i = 0;

	while ((inst + i)->opcode)
	{
		if (strcmp((inst + i)->opcode, *info.arg) == 0)
		{
			(inst + i)->f(stack, info.line_number);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown command %s\n", info.line_number, info.arg[0]);
	free_info();
	return (1);
}
