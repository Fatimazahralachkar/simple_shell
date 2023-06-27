#include "foufa_simple.h"

/**
* _myuser - extract $ to tell user what program
* Owned by: Imane & Fatima Zahra
* The prompt is sealed if the shell is in interactive mode.
* take their input to ON initializing.
* Return: no return
*/
void _myuser(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
/* this symbol has been added by Fatima Zahra*/
