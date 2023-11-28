#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void CheckFileTo(int num, char op, char *fileName)
{	
	if (num == -1 && (op == 'W' || op == 'O'))
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", fileName);
		exit(99);
	}
	else if (num == -1 && op == 'C')
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", fileName);
		exit(100);
	}
}

void CheckFileFrom(int num, char op, char *fileName)
{
	if (num == -1 && (op == 'R' || op == 'O'))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", fileName);
		exit(98);
	}
	else if (num == -1 && op == 'C')
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", fileName);
		exit(100);
	}
}

int main(int argc, char **argv)
{
	int fileTo, fileFrom, lettersRead = -1, lettersWritten = -1;
	char *buffer;
	int temp1, temp2;
	char tempC1, tempC2;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	buffer = malloc(1024);

	fileFrom = open(argv[1], O_RDONLY);
	
	CheckFileFrom(fileFrom, 'O', argv[1]);

	fileTo = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);

	CheckFileTo(fileTo, 'O', argv[2]);

	while (lettersRead != 0)
	{
		lettersRead = read(fileFrom, buffer, 1024);

		CheckFileFrom(lettersRead, 'R', argv[1]);

		lettersWritten = write(fileTo, buffer, lettersRead);

		CheckFileTo(lettersWritten, 'W', argv[2]);
	}


	free(buffer);
	temp1 = close(fileFrom);

	tempC1 = fileFrom + '0';

	CheckFileFrom(temp1, 'C', &tempC1);

	temp2 = close(fileTo);

	tempC2 = fileTo + '0';

	CheckFileTo(temp2, 'C', &tempC2);

	return (0);
}
