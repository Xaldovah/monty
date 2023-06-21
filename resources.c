#include "monty.h"

/**
 * is_num - This func checks for a num in range 0 to 9
 * @str: int to check
 *
 * Return: 1 if num is found, 0 if not
 */
int is_num(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		return (1);
	}
	while (str[i])
	{
		if (is_num(str) == 0)
			return (1);
		i++;
	}
	return (0);
}
