#include "shell.h"
/**
 * error_message - analyses the error code then prints out the message
 * @mytype: Defined struct
 *
 * Return: pointer to the appropreatiate  message
 **/
char *error_message(shell_type mytype)
{
	int i, err_code;

	errors_type msgs[] = {
		{_ENOENT_, 3},
		{_EACCES_, 13},
		{_CMD_NOT_EXISTS_, 132},
		{_ILLEGAL_NUMBER_, 133}
	};

	err_code = sizeof(msgs) / sizeof(msgs[0]);
	for (i = 0; i < err_code; i++)
		if (mytype.current_error == msgs[i].code)
			return (msgs[i].message);

	return ("");
}
