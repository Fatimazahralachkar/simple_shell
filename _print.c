#include "foufa_simple.h"

/**
* _print - environment print to mix for stdout
* Owned by: Imane & Fatima Zahra
*
* Return: nothing 0
*/
void _print(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _stringlg(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
/* this symbol has been added by Fatima Zahra*/
