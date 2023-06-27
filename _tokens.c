#include "foufa_simple.h"

/**
* _tokens - generates tokens from a specified entry
* Owned by: Imane & Fatima Zahra
* @line: process to access its encoding symbolzed
* Return: strings of set
*/
char **_tokens(char *line)
{
	char *buf = NULL, *bufp = NULL, *symbol = NULL, *delim = " :\t\r\n";
	char **symbols = NULL;
	int symbolsize = 1;
	size_t index = 0, flag = 0;

	buf = _stringdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (_stringch(delim, *bufp) != NULL && flag == 0)
		{
			symbolsize++;
			flag = 1;
		}
		else if (_stringch(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	symbols = malloc(sizeof(char *) * (symbolsize + 1));
	symbol = strtok(buf, delim);
	while (symbol)
	{
		symbols[index] = _stringdup(symbol);
		if (symbols[index] == NULL)
		{
			free(symbols);
			return (NULL);
		}
		symbol = strtok(NULL, delim);
		index++;
	}
	symbols[index] = '\0';
	free(buf);
	return (symbols);
}
/* this symbol has been added by Imane*/
