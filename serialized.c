#include "shell.h"
/**
 * serialization - Converts  given number to a string
 * @numm: Number to convert
 *
 * Return: string
 */
char *serialization(int numm)
{
	char *number;
	int total, i;

	total = num_count(numm);
	number = malloc(total * sizeof(char) + 1);
	if (number == NULL)
		return (NULL);
	if (numm == 0)
	{
		number[0] = '0';
		number[1] = '\0';
		return (number);
	}

	number[total] = '\0';

	for (i = total - 1; numm != 0; numm /= 10, i--)
	{
		number[i] = (numm % 10) + '0';
	}

	return (number);
}
