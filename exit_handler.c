#include "shell.h"

/**
 * exit_handler - takes care of contrl -D
 * @line: command line
 * @length: size of the line
 */
void exit_handler(char *line, ssize_t length, char **tokens)
{
	unsigned int i = 0;

	if (_strcmp(line, "exit", 0, 3))
	{
		if (length == -1)
			write(1, "\n", 1);

		while (tokens[i])
		{
			free(tokens[i]);
		}

		free(tokens);
		free(line);

		exit(0);
	}

	if (length == EOF)
	{
		write(1, "\n", 1);
		free(line);
		exit(0);
	}
}
