#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: what to add to the destination string
 *
 * Return: void
 */
void _strcat(char *dest, const char *src)
{
	int i;
	int len = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
		dest[len++] = src[i];

	dest[len] = '\0';
}
