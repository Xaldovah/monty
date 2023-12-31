#include "monty.h"

/**
 * is_num - Checks if a string represents a valid number
 * @str: String to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_num(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		return (0);
	}
	if (str[0] == '-')
	{
		i = 1;
	}
	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * _isdigit - checks for a digit from 0 to 9
 * @str: the integer to be checked
 *
 * Return: 1 if is digit, 0 if not
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (isdigit(*str) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _realloc - reallocates memory block
 * @ptr: pointer
 * @old_size: ...
 * @new_size: ...
 *
 * Return: pointer to new mem
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *res;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		fprintf(stderr, "Error: malloc failed\n");
		free_info();
		exit(EXIT_FAILURE);
	}
	res = malloc(new_size);
	if (res == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_info();
		exit(EXIT_FAILURE);
	}
	if (ptr == NULL)
	{
		_populate(res, '\0', new_size);
		free(ptr);
	}
	else
	{
		memcpy(res, ptr, old_size);
		free(ptr);
	}
	return (res);
}

/**
 * _populate - populates array with elements
 * @i: array
 * @elem: element
 * @len: length array
 *
 * Return: pointer to populated array
 */
void *_populate(void *i, int elem, unsigned int len)
{
	char *p = i;
	unsigned int a = 0;

	while (a < len)
	{
		*p = elem;
		p++;
		a++;
	}
	return (i);
}

/**
 * _getline - This func behaves like the normal getline
 * @lineptr: ...
 * @n: ...
 * @stream: ...
 * Return: pos
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	size_t new_size = *n * 2;
	char *new_lineptr;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (pos + 1 >= *n)
		{
			new_size = *n * 2;
			new_lineptr = realloc(*lineptr, new_size);
			if (new_lineptr == NULL)
				return (-1);
			*lineptr = new_lineptr;
			*n = new_size;
		}
		(*lineptr)[pos++] = (char)c;
		if (c == '\n')
			break;
	}
	if (pos == 0 && c == EOF)
		return (-1);
	(*lineptr)[pos] = '\0';
	return (pos);
}
