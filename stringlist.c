#include "foufa_simple.h"

/**
* _stringdup - repeated string dupicates
* Owned by: Imane & Fatima Zahra
* @s: redundant
* Return: guide string recursive
*/
char *_stringdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
		return (NULL);

	len = _stringlg(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
		ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* _stringlg - string of retrieve length
* Owned by: Imane & Fatima Zahra
* @s: traversal string
* Return: returns string traversal
*/
int _stringlg(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
* _stringcp - it does a comparison between two strings
* Owned by: Imane & Fatima Zahra
* @s1: paired with s2;
* @s2: paired with s1;
* Return: difference between the strings
*/
int _stringcp(char *s1, char *s2)
{
	int i = 0, output;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	output = (*(s1 + i) - *(s2 + i));

	return (output);
}

/**
* _stringch - character string specifies the location
* Owned by: Imane & Fatima Zahra
* @c: character location the identify
* @s: checked string being
* character is not detected, or a NULL operation if
* Return: occurrence of the character re-signal to the first
*/
char *_stringch(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}

/**
* _stringmp - performs a comparison between two strings
* Owned by: Imane & Fatima Zahra
*
* @s1: paired with s2
* @s2: paired with s1
* @n: bytes of number of
*
* Return: between difference s1 and also s2
*/
int _stringmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/* this symbols has been added by Imane and Fatima Zahra*/
