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
