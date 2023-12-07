#include "shell.h"
/**
 * exit _bin- This function helps exit the shell, freeing the memory
 * @mytype: Defined struct
 * @args: argument passed to it
 *
 * Return: void
 */
void exit_bin(shell_type *mytype, char **args)
{
	int state, state_mode;

	state = 1;
	if (args[1] != NULL)
	{
		state = manageNumbers(mytype, args[1]);
	}

	if (state == 0)
	{
		return;
	}

	state_mode = mytype->code_stat;

	free_doublepointer((void **) args);
	free_pointer((void *) mytype->buff);
	free_pointer((void *) mytype->env);
	free_pointer((void *) mytype);

	exit(state_mode);
}

/**
 * env_bin - implements the builtin of the env
 * @mytype: Defined struct
 * @args: Command passed to the shell
 *
 * Return: nothing
 **/
void env_bin(shell_type *mytype, char **args)
{
	(void) mytype;
	(void) args;

	all_env();
}
