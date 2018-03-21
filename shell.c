#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - function to compare strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: integer
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		i++;
	}

	return (0);
}

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		_putchar(13);
}

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

/**
 * main - the root of the shs
 * @ac: arguments counter
 * @av: arguments vector
 * @env: an array of environment key=value pairs
 *
 * Return: 0
 */
int main (int ac, char *av[], char *env[])
{
	size_t buf;
	ssize_t len;
	char *line = NULL;
	char *err_msg = "No such file or directory";

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
		// code for the case when our shell was called as program

	return (0);
}
