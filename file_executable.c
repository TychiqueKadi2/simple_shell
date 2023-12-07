#include "shell.h"
/**
 * executable - checks if file is executable using stat function call
 * @file: file to check
 *
 * Return: 1 if execuatble, else 0
 **/
int executable(char *file)
{
	struct stat stats;

	if (stat(file, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}

	return (-10);
}

/**
 * File - checks if a file or binary
 * @filename: File to check
 *
 * Return: file if file is executable
 */
int File(char *filename)
{
	int i, j;

	j = _strlen(filename);
	for (i = 0; i < j; i++)
		if (filename[i] == '/')
		{
			return (executable(filename));
		}

	return (-10);
}
