#ifndef _shell_h_
#define _shell_h_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int _putchar(char c);
int _strcmp(const char *s1, const char *s2);
void exit_handler(char *line, ssize_t length);
void sig_handler(int sig_num);
char **_strtok(char *string);

#endif
