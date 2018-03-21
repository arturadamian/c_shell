#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char str[80] = "This is - www.tutorialspoint.com - website";
	char *s = "-";
	char *token;

	/* printf("%s\n", str); */
	/* get the first token */
	token = strtok(str, s);

	/* printf("%s\n", str); */

	/* walk through other tokens */
	while (token != NULL) {
	      printf("%s\n", token);
	      token = strtok(NULL, s);
	}

	return(0);
}
