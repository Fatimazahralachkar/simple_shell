#include "foufa_simple.h"
/**
 * _checker - builtin function checks to see what kind of weather
 * Owned by: Imane & Fatima Zahra
 * @cmd: input user
 * @buf: line derivative of the getline function
 *
 * Return: 1 if cmd excuted 0 if cmd is not executed
 */
int _checker(char **cmd, char *buf)
{
	if (_handler(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		usage(cmd[0], cmd);
		return (1);
	}
	return (0);
}
/* this symbol has been added by Fatima Zahra*/
