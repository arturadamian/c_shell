#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		printf("\nreceived SIGINT\n");
		exit(0);
	}
}

int main(void)
{
	ssize_t len;
	char *line = NULL;
	size_t buf;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
		exit(-1);

	while (true)
	{
		len = getline(&line, &buf, stdin);
		if (strcmp(line, "exit") == 0)
			break;

		if (line[len - 1] == 0)
			break;

		if (line[len - 1] == '\n')
			line[len - 1] = '\0';

		printf("%s\n", line);
	}

	return (0);
}
