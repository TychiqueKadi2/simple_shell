#include "shell.h"
/**
 * _env - Helps get environmental variable
 *
 * @varr: environmental variable
 * Return: variable name on success, else return NULL
 */
char *_env(const char *varr)
{
	char **enviro, *au, *token, *i;
	int sizee;

	sizee = _strlen((char *) varr);

	for (enviro = environ; *enviro; ++enviro)
	{
		au = _strdup(*enviro);

		token = strtok(au, "=");
		if (token == NULL)
		{
			free(au);
			return (NULL);
		}

		if (_strlen(token) != sizee)
		{
			free(au);
			continue;
		}
		if (_strcmp((char *) varr, au) == 0)
		{
			token = strtok(NULL, "=");
			i = _strdup(token);
			free(au);
			return (i);
		}
		free(au);
	}
	return (NULL);
}

/**
 * all_env - Helps get all environmental variables
 *
 * Return: none
 **/
void all_env(void)
{
	int i = 0;
	char **temp;

	for (i = 0, temp = environ; temp[i] != NULL; i++)
	{
		_printor(temp[i]);
		_putcharer('\n');
	}
}
