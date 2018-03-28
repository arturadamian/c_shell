#include "shell.h"


/**
 * exit_handler - takes care of contrl -D
 * @line: command line
 * @length: size of the line
 */
void exit_handler(char *line, ssize_t length)
{
	if (_strcmp(line, "exit", 0, 3))
	{
		exit(0);
	}
	else if (line[length - 1] == EOF)
	{
		exit(0);
	}

	(void) length;
}
