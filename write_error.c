#include "shell.h"

/**
 * write_error - writes the error msg to stdout
 * format: e.g. ./hsh: 1: not found
 * @src: the source app, ./hsh
 * @err_code: the errors counter
 * @msg: error message
 */
void write_error(char *src, unsigned int err_code, char *msg)
{
	char *code = _itoa(err_code), *res = NULL;

	_strcpy(res, src);
	_strcat(res, ": ");
	_strcat(res, code);
	_strcat(res, ": ");
	_strcat(res, msg);

	write(STDOUT_FILENO, res, _strlen(res));
}
