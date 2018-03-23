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
	char *line = NULL;
	char **tok_string = NULL;
	char *err_msg = "No such file or directory";
	/* char *tok_string[] = { "/bin/ls", "-la", NULL }; */
	pid_t frk;

	/* signal(SIGINT, sig_handler); */

	if (ac == 1)
		while (true)
		{
			line = NULL;
			printf("($) ");
			getline(&line, &buf, stdin);

			tok_string = _strtok(line);
			frk = fork();
			if (frk < 0)
				return (-1);
			if (frk == 0)
			{
				if (execve(tok_string[0], tok_string, NULL) == -1)
				{
					printf("%s\n", err_msg);
					return (-1);
				}
			}
			else
			{
				wait (NULL);
			}
		}
	else
	{
		(void) av;
		(void) env;
		/* printf("%s\n", err_msg); */
		/* code for the case when our shell was called as program */
	}

	return (0);
}
