#include "shell.h"

/**
 *
 *
 *
 */
void _strtok(char *string, char **tok_string)
{
        unsigned int count = 0;
	char *token;
	/* char *string_copy; */
        /*  */
	/* strcpy(string_copy, string); */

	token = strtok(string, " ");
	while (token)
	{
		count++;
		token = strtok(NULL, " ");
	}
	/* if (token == NULL) */
	/* { */
	/* 	printf("\tNo separators found"); */
	/* 	return; */
	/* } */

	*tok_string = malloc(sizeof(char *) * count + 1);
	if (tok_string == NULL)
		return;

	count = 0;
	/* token = strtok(string_copy, " "); */
	token = strtok(string, " ");
	while (token)
	{
		tok_string[count] = malloc(strlen(token) * sizeof(char) );
		if (tok_string[count] == NULL)
			return;

		tok_string[count] = token;

		count++;
		token = strtok(NULL, " ");
	}

	/* tok_string[count] = NULL; */

	/* tok_string[count] = NULL; */

	/* count = 0; */
	/* while (string_copy_token) */
	/* { */
	/* 	tok_string[count++] = token; */
	/* 	token = strtok(NULL, " "); */
	/* } */
}
