#include "shell.h"


/**
 *
 *
 *
 */
void _strtok(char *string, ssize_t str_len, char **tok_string)
{
        unsigned int count = 0;
	char *token;

	
	token = strtok(string, " ");
	if (token == NULL)
	{
		printf("\tNo separators found");
		return;
	}
	while (token)
	{
		count++;
		token = strtok(NULL, " ");
	}
	tok_string = malloc(sizeof(char) * str_len);
	if (tok_string == NULL)
		return;
	count = 0;
	while (token)
	{
	tok_string[count++] = token;
	token = strtok(NULL, " ");
	}
}
