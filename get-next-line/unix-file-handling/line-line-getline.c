#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	__ssize_t nread;

	if (argc != 2) {
		fprintf(stderr, "Usage: ¨%s <file>\n", *argv);
		exit(EXIT_FAILURE);
	}
	stream = fopen(*++argv, "r");
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1) {
		//printf("Retrieved line of length %zu:\n", nread);
		fwrite(line, nread, 1, stdout);
	}
	if (line) {
		free(line);
	}
	fclose(stream);
	exit(EXIT_SUCCESS);
}
