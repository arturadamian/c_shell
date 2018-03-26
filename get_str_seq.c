#include "shell.h"

/**
 * get_str_seq - takes a sequence from the interval of s[beg:end],
 * then copies it into the string passed by the poiner.
 * @s: string constant from where the token would be taken
 * @beg: the beginning of the interval of s[beg:end]
 * @beg: the end of the interval of s[beg:end]
 * @result: the result
 *
 * Return: void
 */
void get_str_seq(const char *s, int beg, int end, char **res)
{
	int i = 0;

	while (beg != end)
		(*res)[i++] = s[beg++];

	(*res)[i] = '\0';
}
