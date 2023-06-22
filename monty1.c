#include "monty.h"

/**
 * usage_error - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
	fprintf(stderr, "Usage: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * f_open_error - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int f_open_error(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}
/**
 * run_monty - function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
stack_t *stack = NULL;
char *line = NULL, size_t len = 0;
int exit_status = EXIT_SUCCESS;
unsigned int line_number = 0;
char **tokens = tokenize_line(line);
operation_func op_func = get_operation_func(tokens[0]);

if (init_stack(&stack) == EXIT_FAILURE)
	return (EXIT_FAILURE);
while (getline(&line, &len, script_fd) != -1)
{
	line_number++;
	if (tokens == NULL)
	{
		if (is_empty_line(line))
			continue;
		free_stack(&stack);
		free(line);
		return (malloc_error());
	}
	if (is_comment_line(tokens[0]))
	{
		free_tokens(tokens);
		continue;
	}
	if (op_func == NULL)
	{
		free_stack(&stack);
		exit_status = unknown_op_error(tokens[0], line_number);
		free_tokens(tokens);
		break;
	}
	exit_status = op_func(&stack, tokens, line_number);
	free_tokens(tokens);
	if (exit_status != EXIT_SUCCESS)
		break;
}
free_stack(&stack);
free(line);
return (exit_status);
}
