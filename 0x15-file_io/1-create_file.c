#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - create a new file and write in it
 * @filename: name of the file to create
 * @text_content: the text to write in the created file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, lettersWritten, textSize = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	while (text_content[textSize] != '\0')
		textSize++;

	lettersWritten = write(fd, text_content, textSize);

	if (lettersWritten == -1)
		return (-1);

	close(fd);
	return (1);
}
