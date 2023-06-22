#include "monty.h"
/**
 * process_opcodes - Process the opcode based on the input token
 * @opcode: The opcode to process
 * @stack: Pointer to the top of the stack
 *
 * Return: (EXIT_SUCCESS) on success, (EXIT_FAILURE) on error
 */
int process_opcodes(char *opcode, stack_t **stack)
{
int line_number = ();

if (strcmp(opcode, "push") == 0)
{
if (op_toks[1] == NULL || !is_num(op_toks[1]))
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_tokens(op_toks);
	return (EXIT_FAILURE);
}
push(stack, atoi(op_toks[1]));
}
else if (strcmp(opcode, "pall") == 0)
{
	pall(*stack);
}
else if (strcmp(opcode, "pint") == 0)
{
	pint(*stack);
}
else if (strcmp(opcode, "pop") == 0)
{
	pop(stack);
}
else if (strcmp(opcode, "swap") == 0)
{
	swap(stack);
}
else if (strcmp(opcode, "add") == 0)
{
	add(stack);
}
else if (strcmp(opcode, "nop") == 0)
{
	nop(stack);
}
return (EXIT_SUCCESS);
}

/**
 * execute_script - Execute the Monty script
 *
 * @script_fd: File pointer to the Monty script
 *
 * Return: (EXIT_SUCCESS) on success, (EXIT_FAILURE) on error
 */
int execute_script(FILE *script_fd)
{
char *line = NULL;
size_t line_len = 0;
ssize_t read;
int exit_code = EXIT_SUCCESS;
stack_t *stack = NULL;

while ((read = getline(&line, &line_len, script_fd)) != -1)
{
	op_toks = tokenize_line(line);
	if (op_toks == NULL)
		continue;

	exit_code = process_opcodes(op_toks[0], &stack);
	free_token_array(op_toks);

	if (exit_code == EXIT_FAILURE)
		break;
}
free(line);
free_stack(stack);
return (exit_code);
}
