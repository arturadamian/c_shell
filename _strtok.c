#include "shell.h"

/**
 * _strtok - finds and returns
 *
 *
 */
char **_strtok(char *s)
{
        int i = 0;
	Interval itv;
	char *token;
	char **tokens = NULL;
	const int len = _strlen(s);

	int tok_beg = 0, tok_end = 0;

	tokens = malloc(sizeof(char *) * len);
	if (tokens == NULL)
		return (NULL);

	itv = find_str_seq(s, " \t\r\n", tok_beg);
	tok_end = itv.end;

	token = malloc(sizeof(char) * len);
	if (!token)
		return (NULL);

	get_str_seq(s, tok_beg, tok_end, &token);

	tokens[i] = malloc(_strlen(token) * sizeof(char));
	if (tokens == NULL)
		return (NULL);

	_strcpy(tokens[i], token);

	while (len > tok_beg)
	{
		i++;
		tok_beg = tok_end + 1;

		if (len == tok_beg)
		{
			break;
		}

		itv = find_str_seq(s, " \t\r\n", tok_beg);
		tok_end = itv.end;
		get_str_seq(s, tok_beg, tok_end, &token);

		tokens[i] = malloc(_strlen(token) * sizeof(char));
		if (tokens == NULL)
			return (NULL);
		_strcpy(tokens[i], token);
	}

	tokens[i] = NULL;

	return (tokens);
}
