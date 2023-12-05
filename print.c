#include "shell.h"
/**
 * _printf - Print a string to file descriptor
 *
 * @message: prints a string
 * @file_D: File descriptor , print 1, 2 or 0
 *
 * Return: On success numbers of bytes printed is returned
 **/
int _printf(char *message, int file_D)
{
	int buf;

	buf = _strlen(message);
	return (write(file_D, message, buf));
}

/**
 * writeCharacterToFD - prints a character to filr descriptor
 *
 * @chr: Character to print
 * @file_D: specifiy file descriptor to be 0 1 or 2
 *
 * Return: On success 1.
 **/
int _putchar(char chr, int file_D)
{
	return (write(file_D, &chr, 1));
}
