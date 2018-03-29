#include "shell.h"

/**
 * write_prompt - writes the shell prompt
 * @ac: arguments count from the main()
 */
void write_prompt(int ac)
{
	if (ac == 1)
		write(STDOUT_FILENO, "$ ", 2);
}
