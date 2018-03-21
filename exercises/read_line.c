#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "exercises.h"

int main (void)
{
	size_t buf = 0;
	char *line = NULL;

	printf("$ ");
	getline(&line, &buf, stdin);
	/* _getline(&line, &buf, stdin); */
	printf("%s", line);

	return (0);
}
