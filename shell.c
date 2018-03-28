#include "shell.h"

/**
 * main - the root of the shs
 * @ac: arguments counter
 * @av: arguments vector
 * @env: an array of environmental vars, key=value
 *
 * Return: exit code / error code
 */
int main (int ac, char *av[], char *env[])
{
	extern char **environ;
	size_t buf;
	char *line = NULL;
	char **tok_s = NULL;
	char *err_msg = "No such file or directory";
	pid_t frk;

	signal(SIGINT, sig_handler);

	if (ac == 1)
		while (true)
		{
			printf("$ ");

			if (getline(&line, &buf, stdin) == -1)
			{
				_putchar('\n');
				exit(0);
			}

			exit_handler(line, buf);

			tok_s = _strtok(line);

			frk = fork();
			if (frk < 0)
				return (-1);

			if (frk == 0)
			{
				if (execve(path_resolver(environ, tok_s[0]),
							tok_s, NULL) == -1)
				{
					printf("%s\n", err_msg);
					return (-1);
				}
			}
			else
				wait (NULL);
		}
	else
	{
		/* code for the case when our shell was called as program */
		(void) av;
		(void) env;
	}

	return (0);
}
