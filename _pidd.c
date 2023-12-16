#include "shell.h"
/**
 * exec_child - executes child process
 *
 * @cmd: Command to execute
 * @ar: Arguments passed
 * @mytype: Defined struct
 * @buffer: Line readed or created
 *
 * Return: nothing... just perform the task and continue
 **/
void exec_child(char *cmd, char **ar, shell_type *mytype, char *buffer)
{
	int stat;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, ar, environ);
		perror("./sh");

		free_doublepointer((void *) ar);

		if (mytype->cmd_path != NULL)
		{
			free(mytype->cmd_path);
			mytype->cmd_path = NULL;
		}

		free(mytype);
		free(buffer);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &stat, 0);
		if (WIFEXITED(stat))
		{
			mytype->current_stat = WEXITSTATUS(stat);
		}
	}
}
