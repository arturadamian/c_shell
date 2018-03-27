#ifndef _shell_h_
#define _shell_h_

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int _putchar(char c);

void _strcpy(char *dest, const char *src);
int _strlen(const char *s);
void _strcat(char *dest, const char *src);
bool _strcmp(const char *s1, const char *s2, int beg, int end);
char **_strtok(char *s);

int find_str_seq(const char *s, const char *sep, int idx);
void get_str_seq(const char *s, int beg, int end, char **res);

int change_dir(const char *str, char **env);
void sig_handler(int sig_num);
void exit_handler(char *line, ssize_t length);
char *path_resolver(char **env, char *cmd);
void print_env(char **env);
#endif
