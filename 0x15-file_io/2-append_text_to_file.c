#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/**
 * append_text_to_file - a function that appends text at the end of a file
 * @filename: the file to append to
 * @text_content: the text to append
 * Return: 1 if success, -1 if not
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, textLength, lettersWritten;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	textLength = 0;
	while (text_content[textLength] != '\0')
		textLength++;

	lettersWritten = write(fd, text_content, textLength);
	if (lettersWritten == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
