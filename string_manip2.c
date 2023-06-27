#include "header.h"

/**
 * custom_numlen - counts the number of digits in an integer
 * @n: number
 * Owned by: Imane & Fatima Zahra
 * Return: number of digits
 */
int custom_numlen(int n)
{
	int count = 0;
	int num = n;

	while (num != 0)
	{
		num /= 10;
		count++;
	}

	if (n == 0)
		count = 1;

	return (count);
}



/**
 * custom_int_to_string - converts an integer to a string
 * @num: integer to be converted
 * Owned by: Imane & Fatima Zahra
 * Return: pointer to the resulting string
 */
char *custom_int_to_string(int num)
{
	int digit_count = num;
	int tens = 1;
	int i = 0;
	int is_negative = 0;
	int x;
	int size;
	char *result;

	if (num < 0)
		is_negative = 1;
	size = sizeof(char) * (custom_numlen(digit_count) + 2 + is_negative);
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	if (num < 0)
		result[i++] = '-';
	for (x = 0; digit_count > 9 || digit_count < -9; x++)
	{
		digit_count /= 10;
		tens *= 10;
	}
	for (digit_count = num; x >= 0; x--)
	{
		if (digit_count < 0)
			result[i++] = (digit_count / tens) * -1 + '0';
		else
			result[i++] = (digit_count / tens) + '0';
		digit_count %= tens;
		tens /= 10;
	}
	result[i] = '\0';
	return (result);
}

/**
 * custom_atoi - custom atoi function that converts a string to an int
 * @str: string to be converted
 * Owned by: Imane & Fatima Zahra
 * Return: the converted number if successful
 *      -1 if the string contains non-numbers
 */
int custom_atoi(char *str)
{
	int i = 0;
	int num = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		else
		{
			return (-1);
		}

		i++;
	}

	return (num);
}

/**
 * custom_ignore_first_c_strcat - concatenates two strings ignoring 1st char
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *custom_ignore_first_c_strcat(char *dest, const char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 1;

	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	dest = _realloc(dest, len, sizeof(char) * (total_len + 1));

	if (dest == NULL)
		return (NULL);

	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}
