#include "foufa_simple.h"

/**
* _putchar - register character c to stdout
* Owned by: Imane & Fatima Zahra
* @c: character to be written
* moment of the error -1 is returned and errno is set appropriately
* Return: 1 success
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _stringp - string prints
* Owned by: Imane & Fatima Zahra
*
* @s: printed to assortment
* Return: number printed charachters
*/
int _stringp(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
/* this symbol has been added by Fatima Zahra*/
