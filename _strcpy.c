#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: buffer pointer to a destination string
 * @src: string constant to be copied
 *
 * Return: void.
 */
void _strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != 0; i++)
		dest[i] = src[i];

	dest[i] = src[i];
}
