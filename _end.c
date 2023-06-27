#include "foufa_simple.h"

/**
* _end - appends path by adding the path directly to the command
* Owned by: Imane & Fatima Zahra
* @path: path cmd
* @command: user entered the cmd
*
* Return: buffer that includes is on my track order on success
*/
char *_end(char *path, char *command)
{
	char *buf;
	size_t i = 0, j = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_stringlg(path) + _stringlg(command) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (command[j])
	{
		buf[i + j] = command[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
/* this symbol has been added by Fatima Zahra*/
