#include "shell.h"

/**
 * main - the root of the shs
 * @ac: arguments counter
 * @av: arguments vector
 * @env: an array of environmental vars, key=value
 *
 * Return: 0
 */
int main (int ac, char *av[], char *env[])
{
	size_t buf;
	ssize_t len;
	char *line = NULL;
	char *err_msg = "No such file or directory";
	char *tok_string[] = {NULL};
	pid_t frk;

	signal(SIGINT, sig_handler);

	if (ac == 1)
		while (true)
		{
			printf("($) ");
			len = getline(&line, &buf, stdin);

			exit_handler(line, len);

			if (line[len - 1] == '\n')
				line[len - 1] = '\0';

			_strtok(line, tok_string);

			printf("TS0: %s\n", tok_string[0]);

			frk = fork();
			if (frk < 0)
			{
				return (-1);
			}

			if (frk == 0)
			{
				printf("TS0: %s\n", tok_string[0]);
				printf("Child process has started\n");

				if (execve(tok_string[0], tok_string, NULL) == -1)
				{
					printf("fail!");
					return (-1);
				}
			}
			else
				printf("Parent process is waiting\n");
				wait (NULL);
		}
	else
	{
		(void) av;
		(void) env;
		printf("%s\n", err_msg);
		/* code for the case when our shell was called as program */
	}
	return (0);
}
