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

/**
 * _strdup - copies a string
 * @str: String to copy
 *
 * Return: pointer to the newly allocated string in memory
 */
char *_strdup(char *str)
{
	char *dest;
	int str_size, j;

	if (str == NULL)
	{
		return (NULL);
	}

	str_size = _strlen(str) + 1;
	dest = malloc(str_size * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < str_size; j++)
	{
		dest[j] = str[j];
	}

	return (dest);
}
