#include "shell.h"

void exit_handler(char *line, ssize_t length) {
	if (_strcmp(line, "exit") == 0)
	{
		if (length == -1)
			_putchar('\n');
		exit(0);
	}

	if (line[length - 1] == 0)
	{
		_putchar('\n');
		exit(0);
	}
}
