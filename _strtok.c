#include "shell.h"

/**
 *
 *
 *
 */
char **_strtok(char *string)
{
        unsigned int count = 0, i = 0;
	char *token;
	char **tok_string = NULL;

	/* printf("String: %s\n", string); */
	tok_string = malloc(sizeof(char *) * 100);

	if (tok_string == NULL)
		return (NULL);

	for (; i < 100; i++)
		tok_string[i] = malloc(50 * sizeof(char));

	token = strtok(string, " \t\r\n");

	while (token)
	{
		tok_string[count] = token;
		token = strtok(NULL, " \t\r\n");
		/* printf("Count: %d, token: %s\n", count, tok_string[count]); */
		count++;
	}

	tok_string[count] = NULL;
	/* for (i = 0; tok_string[i] != NULL; i++) */
	/* 	printf("%s\n", tok_string[i]); */

	return (tok_string);
}
