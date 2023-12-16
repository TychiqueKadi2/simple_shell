#include "shell.h"
/**
 * current_dir - helps execute a command
 * @commandd: Command to execute is passed here
 * @args: Arguments
 * @buffer: command line read
 * @mytype: Defined struct
 *
 * Return: program state
 */
int current_dir(char *commandd, char **args, char *buffer, shell_type *mytype)
{

	if (mytype->current_path == 0)
	{
		return (0);
	}

	if (executable(commandd) == 1)
	{
		exec_child(commandd, args, mytype, buffer);
		return (1);
	}

	return (0);
}

/**
 * Find_dir - looks for directories
 * @directory: directory to look for
 * @mytype: A struct that defines a certain data type...
 *
 * Return: pointer to a string
 */
char *Find_dir(char *directory, shell_type *mytype)
{
	char *path, *temp, *token, *act;
	int none;

	(void) mytype;

	path = _env("PATH");
	if (path == NULL)
	{
		return (NULL);
	}

	token = strtok(path, ":");

	none = _strlen(directory) + 2;
	act = malloc(none * sizeof(char));
	act = _strcpy(act, "/");
	act = _strcat(act, directory);

	while (token != NULL)
	{
		temp = malloc(_strlen(token) + none);
		temp = _strcpy(temp, token);
		temp = _strcat(temp, act);

		if (executable(temp) == 1)
		{
			free(path);
			free(act);
			return (temp);
		}
		token = strtok(NULL, ":");

		free(temp);
	}

	free(act);
	free(path);

	return (NULL);
}
