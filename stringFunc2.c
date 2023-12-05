#include "shell.h"
/**
 * _strlen - returns length of string
 *
 * @str: string
 *
 * Return: (0)
 */
int _strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
	length++;
	}

	return (length);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: (0) diff == NULL
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int a = 0;

	for (i = 0; s1[i] != '\0' && a == 0; i++)
	{
		a = s1[i] - s2[i];
	}

	return (a);
}
