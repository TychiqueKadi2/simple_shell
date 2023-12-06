#include "shell.h"
/**
 * prompt_info - displays the prompt for simple shell program
 *
 * @mytype: Struct defined in header file
 **/
void prompt_info(shell_type *mytype)
{
	if (mytype->current_mode == 0)
	{
		return;
	}

	_printor("$ ");
}
