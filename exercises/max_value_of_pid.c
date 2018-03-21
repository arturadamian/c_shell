#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	size_t fd, r;
	char *pid_max = "/proc/sys/kernel/pid_max";
	char buff[BUFSIZ];

	fd = open(pid_max, O_RDONLY);
	if (fd == -1)
		exit(-1);

	r = read(fd, buff, 1024);
	if (fd == -1)
		exit(-1);

	printf("/proc/sys/kernel/pid_max == %s", buff);
	printf("r size == %lu", r);

	return (0);
}
