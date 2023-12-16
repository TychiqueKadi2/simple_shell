#include "shell.h"
/**
 * replace_env - Replaces enviromental variable
 * @mytype: Defined struct
 * @var: environmental variable
 *
 * Return: pointer to a string
 */
char *replace_env(shell_type *mytype, char *var)
{
	char *enviro;

	(void) mytype;

	enviro = _env(var);
	if (enviro != NULL)
	{
		return (enviro);
	}

	return (NULL);
}

/**
 * replace_value - replaces pattern value
 * @mytype: Defined struct
 * @pos: handles the  position
 * @str: string input
 *
 * Return: string
 */
char *replace_value(shell_type *mytype, int *pos, char *str)
{
	char *input;
	int i, cur_str, new_str;

	i = *pos;
	i++;

	input = sub(mytype, pos, str + i);
	if (input == NULL)
	{
		str = _strcpy(str, "");

		return (str);
		;
	}

	cur_str = _strlen(str);
	new_str = _strlen(input) + 1;
	str = _realloc(str, cur_str, new_str);
	str = _strcpy(str, input);
	free_pointer(input);

	*pos = i;

	return (str);
}

/**
 * sub - replaces env
 * @mytype: Defined struct
 * @input: parameters passed
 * @word: input words
 *
 * Return: pointer to a string
 */
char *sub(shell_type *mytype, int *input, char *word)
{
	char *temp, signal;

	(void) input;

	signal = *word;
	if (signal != '?' && signal != '$')
	{
		temp = replace_env(mytype, word);
		return (temp);
	}

	temp = (signal == '$') ? serialization(mytype->pid) :
		serialization(mytype->current_stat);

	return (temp);
}
