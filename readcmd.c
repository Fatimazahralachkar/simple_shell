#include "header.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * read_command - reads the user's command from stdin and
 *		stores it into a dynamically allocated buffer
 * @str: pointer to the buffer where the command will be stored
 * Owned by: Imane & Fatima Zahra
 * Return: number of characters read
 */
size_t read_command(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buff[i] = '\0';

		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = custom_strcpy(*str, buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = custom_strcat(*str, buff);
		}
	}
	return (size);
}

