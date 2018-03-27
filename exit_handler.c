#include "shell.h"

void exit_handler(char *line, ssize_t length) {
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
