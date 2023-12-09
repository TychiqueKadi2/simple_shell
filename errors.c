#include "shell.h"
/**
 * print_err - prints to standard error
 *
 * @msg: Message to print
 *
 * Return: bytes
 */
int print_err(char *msg)
{
	return (_printf(msg, 2));
}

/**
 * moreErr_info - Prints error with more information about error encounted
 *
 * @mytype: a defined struct
 * @moreErr: The Extra information
 * Return: none
 */
void moreErr_info(shell_type *mytype, char *moreErr)
{
	char *msge, *n, *au, *au2;
	int n_size, msge_size, sizee;

	n = NULL;
	msge = error_message(*mytype);
	n = serialization(mytype->cmd_num);

	n_size = _strlen(n);
	msge_size = _strlen(mytype->argv[0]);
	sizee = _strlen(moreErr);

	au = malloc(msge_size + n_size + 3);
	au = _strcpy(au, mytype->argv[0]);
	au = _strcat(au, ": ");
	au = _strcat(au, n);

	au2 = malloc(_strlen(msge) + sizee + 3);
	au2 = _strcpy(au2, msge);
	au2 = _strcat(au2, ": ");
	au2 = _strcat(au2, moreErr);

	msge = Fusion(au, mytype->cmd, au2, ": ");
	print_err(msge);

	free(msge);
	free(n);
	free(au);
	free(au2);
}

/**
 * handle_err - handles and prints errors
 *
 * @mytype: Defined struct
 * Return: none
 */
void handle_err(shell_type *mytype)
{
	char *msge, *n, *au;
	int n_size, msge_size;

	n = NULL;
	msge = error_message(*mytype);
	n = serialization(mytype->cmd_num);

	n_size = _strlen(n);
	msge_size = _strlen(mytype->argv[0]);

	au = malloc(msge_size + n_size + 3);

	au = _strcpy(au, mytype->argv[0]);
	au = _strcat(au, ": ");
	au = _strcat(au, n);

	msge = Fusion(au, mytype->cmd, msge, ": ");
	print_err(msge);

	free(msge);
	free(n);
	free(au);
}
