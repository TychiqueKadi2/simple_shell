#include "shell.h"
/**
 * _path - checks the order of the path arrangement
 * @pathh: path to check
 * @mytype: Defined struct
 *
 * Return: none
 */
void _path(char *pathh, shell_type *mytype)
{
	mytype->current_path = 0;

	if (pathh == NULL)
	{
		return;
	}

	if (pathh[0] == ':')
	{
		mytype->current_path = 1;
	}
}
