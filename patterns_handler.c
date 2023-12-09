#include "shell.h"
/**
 * _pattern - collects a pattern and analyzes a pattern
 * @mytype: Defined struct
 * @arggs: argument to anaylze
 * Return: void
 */
void _pattern(shell_type *mytype, char **arggs)
{
	int i;

	for (i = 0; arggs[i] != NULL; i++)
	{
		arggs[i] = process_pattern(mytype, arggs[i]);
	}
}

/**
 * process_pattern - handles a pattern to be analyzed
 * @mytype: Defined struct
 * @str: a pointer to a string pattern
 * Return: a pointer to a string
 */
char *process_pattern(shell_type *mytype, char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '$' && str[i + 1] != '\0')
		{
			str = replace_value(mytype, &i, str);
		}
	}

	return (str);
}
