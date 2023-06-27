#include "header.h"


/**
 * deallocate_strings - Frees dynamically allocated arrays
 * @str: Array of strings
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void deallocate_strings(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

