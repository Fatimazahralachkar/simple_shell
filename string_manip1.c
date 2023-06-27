#include "header.h"

/**
 * custom_strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Owned by: Imane & Fatima Zahra
 * Return: an integer that indicates the difference between the strings
 */

int custom_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;

	if (s2[i] != '\0')
		return (s1[i] - s2[i]);
	else
		return (0);
}

/**
 * custom_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Owned by: Imane & Fatima Zahra
 * Return: copy of original source
 */

char *custom_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}


/**
 * custom_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Owned by: Imane & Fatima Zahra
 * Return: pointer to duplicated string in allocated memory
 */
char *custom_strdup(const char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;
	len++;

	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		duplicate_str[i] = str[i];

	return (duplicate_str);
}

/**
 * custom_strcat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Owned by: Imane & Fatima Zahra
 * Return: concatenated string
 */
char *custom_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int src_len = 0;
	int total_len = 0;
	int i, j;

	while (dest[dest_len] != '\0')
		dest_len++;

	while (src[src_len] != '\0')
		src_len++;

	total_len = dest_len + src_len;

	dest = _realloc(dest, dest_len, sizeof(char) * (total_len + 1));
	if (dest == NULL)
		return (NULL);

	for (i = dest_len, j = 0; j <= src_len; i++, j++)
		dest[i] = src[j];

	return (dest);
}

/**
 * custom_strdup_ebb - custom string duplication; excludes beginning bytes
 * @str: string to duplicate
 * @exclude_bytes: number of bytes to exclude
 * Owned by: Imane & Fatima Zahra
 * Return: string
 */
char *custom_strdup_ebb(char *str, int exclude_bytes)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	duplicate_str = malloc(sizeof(char) * (len - exclude_bytes));
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - exclude_bytes))
	{
		*(duplicate_str + i) = *(str + exclude_bytes + i);
		i++;
	}
	return (duplicate_str);
}

