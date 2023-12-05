#include "shell.h"

/**
 * _strcat - concatenate two strings
 *
 * @dest: string to concatenate
 * @src: string to string
 *
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len1, len2, i;

	for (len1 = 0; dest[len1] != '\0'; len1++)
	{

	}

	for (len2 = 0; src[len2] != '\0'; len2++)
	{

	}
	for (i = 0; i <= len2; i++)
	{
		dest[len1 + i] = src[i];
	}

	return (dest);
}

/**
 * *_strcpy - pointer to a character
 *
 * @dest: string 1 pointer to a char
 * @src: string 2 pointer to a char
 * Return: character (dest)
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
