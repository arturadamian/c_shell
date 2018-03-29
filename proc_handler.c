#include "shell.h"

/**
 * proc_handler - creates and handles the child process
 * @path: command or resolved path to executable
 * @toks: array of tokens to pass to execve() function
 * @err_msg: an error message
 * @c: errors counter
 *
 * Return: void
 */
void proc_handler(char *path, char **toks, char *err_msg, unsigned int c)
{
	pid_t pid = fork();

	if (pid < 0)
		exit(-1);

	if (pid == 0)
	{
		if (execve(path, toks, NULL) == -1)
		{
			write_error(path, ++c, err_msg);
			exit(-1);
		}
	}
	else
	{
		wait(NULL);
	}
}
