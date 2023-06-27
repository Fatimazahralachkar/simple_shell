#include "header.h"

/**
 * ignore_delm - returns a version of string without preceeding delims
 * @str: string
 * @delm: delimiter
 * Owned by: Imane & Fatima Zahra
 * Return: new string
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delm: delimeter
 * Owned by: Imane & Fatima Zahra
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0;
	int len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];

	str = ignore_delm(str, d_ch);

	buffsize = count_delimiters(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		if (str[si] != d_ch)
		{
			len = get_token_length(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0';
			t++;
		}
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
}


/**
 * str_tokenize - tokenizes a string and returns an array of tokens
 * @str: input string to tokenize
 * @delim: delimiter string (e.g. " ")
 * Return: an array of tokens
 */
char **str_tokenize(char *str, char *delim)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **tokens = NULL, delim_ch;

	delim_ch = delim[0];

	str = ignore_delm(str, delim_ch);

	buffsize = count_delimiters(str, delim_ch);
	tokens = malloc(sizeof(char *) * (buffsize + 2));
	if (tokens == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		if (str[si] != delim_ch)
		{
			len = get_token_length(str, si, delim_ch);
			tokens[p] = malloc(sizeof(char) * (len + 1));
			if (tokens[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != delim_ch) && (str[si] != '\0'))
			{
				tokens[p][i] = str[si];
				i++;
				si++;
			}
			tokens[p][i] = '\0';
			t++;
		}

		if (si < se && (str[si + 1] != delim_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	tokens[p] = NULL;
	return (tokens);
}

/**
 * custom_str_tokenize - tokenizes a string even with continuous delimiters
 * @str: user's command typed into shell
 * @delim: delimiter
 * Owned by: Imane & Fatima Zahra
 * Return: an array of tokens
 */
char **custom_str_tokenize(char *str, char *delim)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **tokens = NULL, delimiter;

	delimiter = delim[0];
	buffsize = count_tokens(str, delimiter);
	tokens = malloc(sizeof(char *) * (buffsize + 2));
	if (tokens == NULL)
		return (NULL);

	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		len = get_token_length(str, si, delimiter);
		tokens[p] = malloc(sizeof(char) * (len + 1));
		if (tokens[p] == NULL)
			return (NULL);
		i = 0;
		while ((str[si] != delimiter) && (str[si] != '\0'))
		{
			tokens[p][i] = str[si];
			i++;
			si++;
		}
		tokens[p][i] = '\0';
		p++;
		si++;
	}
	tokens[p] = NULL;
	return (tokens);
}

