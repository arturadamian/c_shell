#include "shell.h"

/**
 * main - the root of the shs
 * @ac: arguments counter
 * @av: arguments vector
 * @env: an array of environmental vars, key=value
 *
 * Return: 0
 */
int main(int ac, char *av[], char *env[])
{
	size_t buf;
	char *line = NULL, *err_msg = "No such file or directory";
	char **tok_s = NULL;
	pid_t frk;

	if (ac == 1)
		while (true)
		{
			line = NULL;
			_putchar('$');
			_putchar(' ');
			getline(&line, &buf, stdin);
			exit_handler(line, buf);
			tok_s = _strtok(line);
			if (_strcmp(tok_s[0], "env", 0, 2))
				print_env(env);
			frk = fork();
			if (frk < 0)
				return (-1);
			if (frk == 0)
			{
				if (execve(path_resolver(env, tok_s[0]),
							tok_s, NULL) == -1)
				{
					write(STDOUT_FILENO, err_msg, 25);
					return (-1);
				}
			}
			else
			{
				wait(NULL);
			}
		}
	else
	{
		(void) av;
		(void) env;
	}
	return (0);
}
