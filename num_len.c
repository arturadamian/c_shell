#include "shell.h"

/**
 * num_len - returns the length of number
 * as if it is a string
 * @n: number, unsigned integer
 *
 * Return: number lenght
 */
unsigned int num_len(unsigned int n)
{
	unsigned int len = 0;

	while (n != 0)
	{
		n /= 10;
		len++;
	}

	return (len);
}
