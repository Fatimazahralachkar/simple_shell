#include "header.h"


/**
 * get_token_length - returns the length of a token
 * @str: input string containing tokens
 * @pos: starting position of the token
 * @delim: delimiter character
 * Owned by: Imane & Fatima Zahra
 * Return: length of the token
 */
int get_token_length(char *str, int pos, char delim)
{
	int length = 0;

	while ((str[pos] != delim) && (str[pos] != '\0'))
	{
		pos++;
		length++;
	}
	return (length);
}



/**
 * count_delimiters - returns the number of delimiters
 * @str: input string
 * @delim: delimiter character
 * Ownzded by: Imane & Fatima Zahra
 * Return: number of delimiters
 */
int count_delimiters(char *str, char delim)
{
	int i = 0, num_delimiters = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delim) && (str[i + 1] != delim))
		{
			num_delimiters++;
		}
		if ((str[i] == delim) && (str[i + 1] == '\0'))
		{
			num_delimiters--;
		}
		i++;
	}
	return (num_delimiters);
}



/**
 * count_tokens - returns the number of tokens delimited by a spec char
 * @str: input string to count tokens from
 * @delim: delimiter character
 * Owned by: Imane & Fatima Zahra
 * Return: number of tokens
 */
int count_tokens(char *str, char delim)
{
	int i = 0, num_tokens = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			num_tokens++;
		}
		i++;
	}
	return (num_tokens);
}

