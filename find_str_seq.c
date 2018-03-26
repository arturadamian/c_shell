#include "shell.h"

/**
 * find_str_seq - finds the index of the separator `sep`
 * inside the string `s`, starting from the index `idx`
 * @s: string constant where to search
 * @sep: the separator(s) to search for
 * @idx: the position of the string from where to start
 *
 * Return: the index of the `sep` inside the string `s`
 */
int find_str_seq(const char *s, const char *sep, int idx)
{
	int i = 0;

	/* form the array of 2 elements */
		/* 0: 1st separator */
		/* 1: separator next to it */

	while (sep[i])
	{
		while (s[idx])
		{
			/* printf("sep[i]: %c, s[idx]: %c\n", sep[i], s[idx]); */
			if (s[idx] == sep[i])
				return (idx);

			idx++;
		}
		i++;
	}

	return (idx);
}
