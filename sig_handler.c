#include "shell.h"

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		_putchar(13);
}
