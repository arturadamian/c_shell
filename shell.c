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
	unsigned int c = 0;
	size_t buf;
	ssize_t ch;
	pid_t pid;
	char **tok_s = NULL;
	char *path = NULL;
	char *line = NULL, *err_msg = "not found";

	while (true)
	{
		signal(SIGINT, sig_handler);
		write_prompt(ac);

		ch = getline(&line, &buf, stdin);
		tok_s = _strtok(line);

		if (!env_handler(tok_s[0], env))
		{
			exit_handler(line, ch, tok_s);

			path = path_resolver(env, tok_s[0]);

			if (!path)
				printf("%s: %d: %s\n", av[0], ++c, err_msg);
			else
			{
				pid = fork();
				if (pid < 0)
					return (-1);

				if (pid == 0)
				{
					if (execve(path, tok_s, NULL) == -1)
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
		}

		while (tok_s[c])
			free(tok_s[c++]);
		free(tok_s);
	}

	(void) ac;
	(void) av;
	(void) env;

	return (0);
}
