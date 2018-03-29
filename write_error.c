#include "shell.h"

/**
 * write_error - writes the error msg to stdout
 * format: e.g. ./hsh: 1: not found
 * @app: the source app, ./hsh
 * @src: the command that coused the error
 * @err_code: the errors counter
 * @msg: error message
 */
void write_error(char *app, char *src, unsigned int err_code, char *msg)
{
	char *code = _itoa(err_code), *res = NULL;
	int len = _strlen(code)
		+ _strlen(src)
		+ _strlen(msg)
		+ _strlen(app)
		+ 6;

	res = malloc((sizeof(char) + 1) *  len);
	if (res == NULL)
		exit(1);

	_strcpy(res, app);
	_strcat(res, ": ");
	_strcat(res, code);
	_strcat(res, ": ");
	_strcat(res, src);
	_strcat(res, ": ");
	_strcat(res, msg);

	write(STDOUT_FILENO, res, _strlen(res));
}
