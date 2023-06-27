#include "foufa_simple.h"
/**
* main - he does the reading
* All rights reserved or owned by noiseworking
*
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: nothing 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, _handler2);
	while (1)
	{
		_supplies(command);
		_supplies(paths);
		free(pathcommand);
		_myuser();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = _tokens(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (_checker(command, line))
			continue;
		path = _pathfind();
		paths = _tokens(path);
		pathcommand = _pathvalid(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			usage(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
/* this symbol has been added by Imane*/
