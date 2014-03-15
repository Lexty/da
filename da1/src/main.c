#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "counting-sort.h"

#define EXIT_ERROR 0
#define BUFFERSIZE 1000
#define ERRMSGSIZE 100

void *dmalloc(size_t size);
void *drealloc(void *ptr, size_t size);
void handle_error(const int code);

int main()
{
	size_t reqmem = 1;
	char *text = dmalloc(reqmem), buffer[BUFFERSIZE];
	printf("> ");
	while(fgets(buffer, BUFFERSIZE, stdin)) {
		if (buffer[0] == '\n') {
			if (isatty(STDIN_FILENO))
				break;
			else
				continue;
		}
		reqmem += strlen(buffer) + 1;
		text = drealloc(text, reqmem);
		strcat(text, buffer);
		printf("%s", buffer);
		printf("> ");

	}
	printf("\ntext:\n%s",text);

	free(text);

	printf("\n");
	exit(EXIT_SUCCESS);
}

void *dmalloc(size_t size)
{
	void *p = malloc(size);
	if (!p)
		handle_error(errno);
	return p;
}

void *drealloc(void *ptr, size_t size)
{
	void *p = realloc(ptr, size);
	if (!p)
		handle_error(errno);
	return p;
}

void handle_error(const int code)
{
	char msg[ERRMSGSIZE];
	if (code > 0)
		strcpy(msg, strerror(code));
	else
		switch (code) {
			case EXIT_SUCCESS:
				strcpy(msg, "Nothing happened");
				break;
			default:
				sprintf(msg, "Unknown error %d", code);
				break;
		}
	fprintf(stderr, "Error: %s\n", msg);
	exit(EXIT_ERROR);
}
