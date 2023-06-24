#include "monty.h"

#define BUFFER_SIZE 1024

info_t info;

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int ac, char **av)
{
	ssize_t new_read = 1;
	size_t len = 0;
	stack_t *stack = NULL;

	memset((void *) &info, 0, sizeof(info));
	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.filename = av[1];
	info.fon = fopen(info.filename, "r");
	if (info.fon == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((new_read = _getline(&info.line, &len, info.fon)) > 0)
	{
		if (*info.line == '\n')
		{
			continue;
		}
		info.line_number++;
		free(info.arg);
		if (_token() < 0)
		{
			continue;
		}
		if (*info.arg == NULL)
			continue;
		p_init(&stack);
	}
	free_info();
	free_list(stack);
	free(info.line);
	info.line = NULL;
	fclose(info.fon);
	return (EXIT_SUCCESS);
}
