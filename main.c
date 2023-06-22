#include "monty.h"

info_t info;

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		parse_line(line, &stack, line_number);
	}
	free(line);
	fclose(file);
	free_list(stack);
	return (EXIT_SUCCESS);
}

/**
 * parse_line - Parses a line of Monty bytecode
 * @line: Line of Monty bytecode to parse
 * @stack: Pointer to the stack
 * @line_number: Line number of the bytecode
 */
void parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *arg;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL || !is_num(arg))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		push(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}
