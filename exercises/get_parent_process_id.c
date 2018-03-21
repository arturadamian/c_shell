#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid, parent_pid;

	my_pid = getpid();
	printf("Process ID of the running program: %u\n", my_pid);

	parent_pid = getppid();
	printf("Process ID of its parent: %u\n", parent_pid);

	return (0);
}
