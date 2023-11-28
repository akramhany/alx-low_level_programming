#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the filename which we would read from
 * @letters: number of letters to be read and written
 * Reaturn: actual number of letters read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, lettersRead, lettersWritten;
	char *buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	lettersRead = read(fd, buffer, letters);

	if (lettersRead == -1)
		return (0);

	lettersWritten = write(STDOUT_FILENO, buffer, lettersRead);

	if (lettersWritten != lettersRead || lettersWritten == -1)
		return (0);

	return (lettersWritten);
}
