#include <stdio.h>

/**
  * isMersenne - tests if a number is a Mersenne's number
  * @num: the number to be tested and checked
  * Owned by: Imane and Fatima Zahra
  * Return: 0 if true(if num is a Mersenne's number) and 1 if not
  */
int isMersenne(int num)
{
	int k = 0;
	int power = 1;
	int mersenne;

	while (power <= num + 1)
	{
		power *= 2;
		k++;
	}

	mersenne = power - 1;

	return (mersenne == num);
}

/**
 * main - entry point
 * Return: 0
*/

int main(void)
{
	int number;

	printf("Enter a number: ");
	scanf("%d", &number);

	if (isMersenne(number))
	{
		printf("%d is a Mersenne number.\n", number);
	}
	else
	{
		printf("%d is not a Mersenne number.\n", number);
	}

	return (0);
}
