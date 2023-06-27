#include "foufa_simple.h"

/**
 * _handler2 - continue to maintain the track is interactive mode
 * Owned by: Imane & Fatima Zahra
 *
 * @m: the signal number
 * Return: nothing
 */

void _handler2(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
/* this symbol has been added by Imane */
