#include "shell.h"
/**
 * cmd_args - analyzes arguements passed to prompt
 *
 * @args: arguments
 * @mytype: Defined struct
 * @buffer: Line read
 *
 * Return: none
 **/
void cmd_args(char **args, shell_type *mytype, char *buffer)
{
	char *comand;
	int analysis;

	if (*args == NULL || args == NULL)
	{
		return;
	}
	comand = args[0];
	mytype->cmd = comand;
	if (check_builtin(mytype, args) == 1)
	{
		return;
	}
	analysis = isFile(comand);
	if (analysis == 0)
	{
		mytype->current_state = 126;
		mytype->current_error = 13;
		issue(mytype);
		return;
	}
	if (analysis == 1)
	{
		exec_child(comand, args, mytype, buffer);
		return;
	}
	if (current_dir(comandd, args, buffer, mytype) == 1)
		return;
	mytype->cmd_path = Find_dir(comand, mytype);
	if (mytype->cmd_path != NULL)
	{
		exec_child(mytype->cmd_path, args, mytype, buffer);
		free_pointer((void *) mytype->cmd_path);
		return;
	}
	mytype->current_state = 127;
	mytype->current_error = 132;
	issue(mytype);
}
