#include "foufa_simple.h"

/**
* _handler - it implements functions integrated with handling
* Owned by: Imane & Fatima Zahra
* @line: read or process input information from stdin
* @command: symbolzed commands
*
* Return: 0 if not , 1 if executed
*/
int _handler(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_stringcp(*command, builtin.env) == 0)
	{
		_print();
		return (1);
	}
	else if (_stringcp(*command, builtin.exit) == 0)
	{
		_exitcmd(command, line);
		return (1);
	}
	return (0);
}
/* this symbol has been added by fatima zahra */
