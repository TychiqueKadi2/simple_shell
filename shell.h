#ifndef SHELL_H
#define SHELL_H

/** used libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>

/** macros */
#define MAX_CMD_LENGTH 100
#define _EACCES_ "Permission denied"
#define _CMD_NOT_EXISTS_ "not found"
#define _ILLEGAL_NUMBER_ "Illegal number"
#define _ENOENT_ "No such file or directory"

/** environ var */
extern char **environ;


char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
int _printf(char *message, int file_D);
int _putchar(char chr, int file_D);
int _printor(char *message);
void prompt_info(shell_type *mytype);
void infinityPrompt(shell_type *mytype);
char *parse_prompt(void)

/**
 * argc: count of command-line arguments.
 * *argv: actual command-line arguments as an array of strings.
 * cmd: command to be executed.
 * cmd_path: path of the command to be executed.
 * buff: buffer for strings input or output.
 * *argss: arguments for a command.
 * env: environment variables.
 * pid: store a process ID.
 * current_mode: store a mode for iteration.
 * cmd_num: number of commands.
 * current_path: store the current path index.
 * current_stat: store a status code.
 * current_error: store an error code.
*/
typedef struct __attribute__((__packed__))
{
	int argc;
	char **argv;
	char *cmd;
	char *cmd_path;
	char *buff;
	char **argss;
	char *env;
	int pid;
	int current_mode;
	int cmd_num;
	int current_path;
	int current_stat;
	int current_error;
} shell_type;

#endif
