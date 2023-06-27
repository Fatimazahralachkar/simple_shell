#include "foufa_simple.h"

/**
* _supplies - supplies for free
* Owned by: Imane & Fatima Zahra
*
* @buf: buffer to be released
* Return: no return
*/
void _supplies(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
/* this symbol has been added by Imane*/
