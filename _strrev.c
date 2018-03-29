#include "shell.h"

/**
 * _strrev - returns reversed string
 * @str: string to be reversed
 *
 * Return: reversed string
 */
char *_strrev(char *str)
{
	int i;
	int len = _strlen(str);
	char c;

	if (!str)
		return (NULL);

	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}

	return (str);
}

