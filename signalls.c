#include "shell.h"
/**
 * sigint_handler - handle SIGINT
 * @sig: a paramete
 *
 * Return: do nothing ((fflush flushes out content of output string))
 **/
void sigint_handler(int sig)
{
	(void) sig;

	signal(SIGINT, sigint_handler);
	_printor("\n$ ");
	fflush(stdout);
}
