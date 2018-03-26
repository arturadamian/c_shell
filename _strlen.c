/**
 * _strlen - finds the length of the string
 * @s: a string constant
 *
 * Return: the length of the string s
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
