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
