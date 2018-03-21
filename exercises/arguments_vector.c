#include <stdio.h>

int main(int ac, char **av)
{
	(void) ac;

	while (*av)
		printf("%s\n", *av++);

	return (0);
}
