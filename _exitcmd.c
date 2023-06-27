#include "foufa_simple.h"

/**
* _exitcmd - exit order handling
* Owned by: Imane & Fatima Zahra
* @command: symbolzed
* @line: Read input stdin
*
* Return: no return
*/
void _exitcmd(char **command, char *line)
{
	free(line);
	_supplies(command);
	exit(0);
}
/* this symbol has been added by Imane*/
