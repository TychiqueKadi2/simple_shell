#include "shell.h"
/**
 * check_builtin - confirms a builtin cmd
 * @mytype: Defined struct
 * @args: argument count
 *
 * Return: 1 if builtin, else 0
 **/
int check_builtin(shelldata_t *mytype, char **args)
{
	int a, none;

	sysfunc_type builtins[] = {
		{"exit", binaryExit},
		{"env", binaryEnv}
	};

	none = sizeof(builtins) / sizeof(builtins[0]);
	a = 0;
	while (a < none)
	{
		if (_strcmp(mytype->cmd, builtins[a].cmd) == 0)
		{
			builtins[a].func(mytype, args);
			return (1);
		}
		a++;
	}

	return (0);
}

/**
 * find_sysfuncs - check for builtins
 * @mytype: Defined struct
 * @args: commands
 *
 * Return: 1 if buitin command, else  0
 */
int find_sysfuncs(shell_type *mytype, char **args)
{
	int new;

	new = verifyBuiltin(mytype, args);
	if (new == 0)
	{
		return (0);
	}

	return (1);
}
