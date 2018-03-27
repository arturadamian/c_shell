#include "shell.h"

/**
 *
 */
int find_chars_number(const char *s, const char *c, int idx)
{
	int i, j, q;

	j = q = 0;
	i = idx;

	while (c[j])
	{
		i = idx;
		while (s[i])
		{
			if (s[i] == c[j])
				q++;

			i++;
		}

		j++;
	}

	return (q);
}

