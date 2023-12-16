#include "shell.h"
/**
 * exit_binSupport - Controls the argument of exit builtin
 * @mytype: a pointer to a struct to access its types
 * @arggg: Argument passed
 *
 * Return: If arguement is valid 1, else return 0
 */
int exit_binSupport(shell_type *mytype, char *arggg)
{
	int i;

	i = _atoi(arggg);

	if (i < 0 || letter_search(arggg))
	{
		mytype->current_stat = 2;
		mytype->current_error = 133;
		moreErr_info(mytype, arggg);
		return (0);
	}

	if (i > 255)
	{
		mytype->current_stat = i % 256;
	}
	else
	{
		mytype->current_stat = i;
	}

	return (1);
}
