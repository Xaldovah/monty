#include "monty.h"

/**
 * _token - This func splits lines into toks
 *
 * Return: a pos (if it succeeds) or neg number (if it fails)
 */
int _token(void)
{
	char *tok;
	size_t size = 4, new_size, i = 0;

	info.arg = malloc(size * sizeof(char *));
	if (info.arg == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_info();
		exit(EXIT_FAILURE);
	}
	tok = strtok(info.line, DELIMS);
	while (tok)
	{
		info.arg[i++] = tok;
		if (i >= size)
		{
			new_size = size * 2;
			info.arg = _realloc(info.arg, size * sizeof(char *),
					new_size * sizeof(char *));
			if (info.arg == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free_info();
				exit(EXIT_FAILURE);
			}
			size = new_size;
		}
		tok = strtok(NULL, DELIMS);
	}
	info.arg[i] = NULL;
	if (**info.arg == '#')
	{
		return (-1);
	}
	return (0);
}
