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

	(void) av;
	(void) env;
	signal(SIGINT, sig_handler);

	if (ac == 1)
		while (true)
		{
			printf("($) ");
			len = getline(&line, &buf, stdin);

			exit_handler(line, len);

			if (line[len - 1] == '\n')
				line[len - 1] = '\0';
		}
	else
		printf("%s\n", err_msg);
		/* code for the case when our shell was called as program */

	return (0);
}
