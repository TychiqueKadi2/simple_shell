#include "shell.h"
/**
 * number_search - Checks if a input parameter is a digit
 *
 * @X: input to check
 * Return: 1 if digit, else return 0
 */
int number_search(unsigned int X)
{
	return (X >= '0' && X <= '9');
}

/**
 * letter_search - checks if a digit string has any letters
 *
 * @str: String to check for letter
 * Return: 1 if letter found, else return 0
 **/
int letter_search(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (number_search(str[i]) == 0)
			return (1);
	}

	return (0);
}
