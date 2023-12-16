#include "shell.h"
/**
 * num_count - Counts digits in a number
 * @number: Number inputed
 *
 * Return: numbers counted
 */
int num_count(int number)
{
	int i = 0;

	while (number != 0)
	{
		i++;
		number = number / 10;
	}

	return (i);
}
