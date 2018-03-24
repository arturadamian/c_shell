#include "shell.h"

/* string comparator */
bool s_c(char *s1, char *s2, int beg, int end)
{
	if (!s1 && !s2)
		return (true);

	if (!s1 || !s2 || beg > end)
		return (false);

	do {
		if (s1[beg] != s2[beg])
			return (false);

		beg++;
	} while (beg != end);

	return (true);
}

void get_token(char *s, int beg, int end, char **t)
{
	int i = 0;

	while (beg != end)
		(*t)[i++] = s[beg++];

	(*t)[i] = '\0';

	/* printf("get_token: (%s)\n", *t); */
}

int find_token(char *s, char sep, int idx)
{
	while (s[idx] && s[idx] != sep)
	{
		/* printf("%c", s[idx]); */
		idx++;
	}
	/* printf("\n"); */

	/* printf("find_token: (%d)\n", idx); */
	return (idx);
}


char *path_resolver(char **env, char *cmd)
{
	/* struct stat sb; */
	char *path;
	int path_len = 0;
	char *tok;
	char *bin;
	int c, tok_beg = 0, tok_end = 5;

	for (c = 0; env[c]; c++)
		if (s_c("PATH=", env[c], tok_beg, tok_end - 1))
			path = env[c];

	path_len = strlen(path);
	tok_beg = tok_end + 1; /* separator */
	tok_end = find_token(path, ':', tok_beg);

	tok = malloc(sizeof(char) * (tok_end - tok_beg));
	if (!tok)
		return (NULL);

	bin = malloc(sizeof(tok) + sizeof(cmd));
	if (!bin)
		return (NULL);

	get_token(path, tok_beg, tok_end, &tok);

	strcpy(bin, tok);
	strcat(bin, "/");
	strcat(bin, cmd);

	while (access(bin, F_OK) == -1) {
		/* file doesn't exist */

		/* no more tokens in the path */
		/* return the command as is */
		if (path_len == tok_end)
			return (cmd);

		tok_beg = tok_end + 1; /* separator */
		tok_end = find_token(path, ':', tok_beg);

		get_token(path, tok_beg, tok_end, &tok);

		strcpy(bin, tok);
		strcat(bin, "/");
		strcat(bin, cmd);

		/* printf("%s\n", bin); */
	}
		/* printf("No executable `%s` was found in `%s`", cmd, bin); */
	/* file exists */
	return (bin);
}

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
	extern char **environ;
	size_t buf;
	char *line = NULL;
	char **tok_s = NULL;
	char *err_msg = "No such file or directory";
	pid_t frk;

	/* signal(SIGINT, sig_handler); */

	if (ac == 1)
		while (true)
		{
			line = NULL;
			printf("($) ");
			getline(&line, &buf, stdin);

			tok_s = _strtok(line);

			/* while (*environ) */
			/* 	printf("%s\n", *environ++); */


			frk = fork();
			if (frk < 0)
				return (-1);

			if (frk == 0)
			{
				/* printf("%s\n", path_resolver(environ, tok_s[0])); */
				if (execve(path_resolver(environ, tok_s[0]),
							tok_s, NULL) == -1)
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
