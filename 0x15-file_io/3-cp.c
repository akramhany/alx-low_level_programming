#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fileTo, fileFrom, lettersRead = -1, lettersWritten = -1;
	char *buffer;
	int temp1, temp2;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	buffer = malloc(1024);

	fileFrom = open(argv[1], O_RDONLY);

	if (fileFrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	fileTo = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);

	if (fileTo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	while (lettersRead != 0)
	{
		lettersRead = read(fileFrom, buffer, 1024);

		if (lettersRead == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		lettersWritten = write(fileTo, buffer, lettersRead);

		if (lettersWritten == -1 || lettersWritten != lettersRead)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
	}


	free(buffer);
	temp1 = close(fileFrom);

	if (temp1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileFrom);
		exit(100);
	}

	temp2 = close(fileTo);

	if (temp2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileTo);
		exit(100);
	}

	return (0);
}
