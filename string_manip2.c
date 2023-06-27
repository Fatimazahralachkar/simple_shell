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

