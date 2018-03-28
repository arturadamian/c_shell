#include "shell.h"

/**
 * _strtok - parsing the string
 * @s: pointer to a string
 *
 * Return: array of strings
 */
char **_strtok(char *s)
{
	unsigned int i;
	char *token;
	char **tokens = NULL;
	const unsigned int len = _strlen(s);

	tokens = malloc(len * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = strtok(s, " \t\r\n");

	i = 0;
	while (token)
	{
		tokens[i] = malloc(_strlen(token) * (sizeof(char) + 1));
		if (tokens == NULL)
			return (NULL);

		tokens[i] = token;
		token = strtok(NULL, " \t\r\n");
		i++;
	}

	tokens[i] = NULL;

	return (tokens);
}
