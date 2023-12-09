#include "shell.h"
/**
 * main - The simple shell main program runs a basic shell
 *
 * @ac: argument count
 * @av: arguments vector
 * Return: 0
 */
int main(int ac, char **av)
{
	int state;
	shell_type *mytype;

	mytype = malloc(sizeof(shell_type));
	if (mytype == NULL)
	{
		perror(av[0]);
		exit(1);
	}

	mytype->pid = getpid();
	mytype->current_state = 0;
	mytype->cmd_num = 0;
	mytype->argc = ac;
	mytype->argv = av;
	mytype->current_mode = isatty(0) == 1;
	runn(mytype);

	state = mytype->current_state;

	free(mytype);

	return (state);
}
