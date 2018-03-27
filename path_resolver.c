#include "shell.h"

/**
 * path_resolver - resolves the PATH to a commpand `cmd`
 * using the environment `env`
 * @env: the pointer to a environ/argv
 * @cmd: the string with a command
 *
 * Return: the resolved path to executable `cmd`, if it
 * exists, otherwise the `cmd` as is
 */
char *path_resolver(char **env, char *cmd)
{
	char *path, *tok, *bin;
	int c, path_len = 0, tok_beg = 0, tok_end = 5;

	/* printf("separator is at the index #: %d", find_str_seq) */
	for (c = 0; env[c]; c++)
		if (_strcmp("PATH=", env[c], tok_beg, tok_end - 1))
			path = env[c];
	/* lol_ololo(path, tok, tok_beg, tok_end); */
	path_len = _strlen(path);
	tok_beg = tok_end + 1; /* separator */
	tok_end = find_str_seq(path, ":", tok_beg);
	tok = malloc(sizeof(char) * (tok_end - tok_beg));
	if (!tok)
		return (NULL);
	bin = malloc(sizeof(tok) + sizeof(cmd));
	if (!bin)
		return (NULL);
	get_str_seq(path, tok_beg, tok_end, &tok);
	_strcpy(bin, tok);
	_strcat(bin, "/");
	_strcat(bin, cmd);
	while (access(bin, F_OK) == -1)
	{
		/* file doesn't exist */
		/* no more tokens in the path */
		/* return the command as is */
		if (path_len == tok_end)
			return (cmd);
		tok_beg = tok_end + 1; /* separator */
		tok_end = find_str_seq(path, ":", tok_beg);
		get_str_seq(path, tok_beg, tok_end, &tok);
		_strcpy(bin, tok);
		_strcat(bin, "/");
		_strcat(bin, cmd);
	}
	/* file exists */
	return (bin);
}
