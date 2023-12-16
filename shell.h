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


/**
 * message: a pointer to message
 * code: permissions code
 */
typedef struct __attribute__((__packed__))
{
	char *message;
	int code;
} errors_type;


/**
 * commands: a pointer to command
 * func: a pointer to a shell_type and to a double  pointer to
 */
typedef struct __attribute__((__packed__))
{
	char *command;
	void (*func)(shell_type *mytype, char **arguments);
} sysfunc_type;


char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strdup(char *str);
int _printf(char *message, int file_D);
int _putchar(char chr, int file_D);
int _printor(char *message);
int _putcharer(char chr);
void prompt_info(shell_type *mytype);
void infinity_Prompt(shell_type *mytype);
char *parse_prompt(void);
void free_pointer(void *pointer);
void free_doublepointer(void **pointer);
void sigint_handler(int sig);
void *_realloc(void *ptr, unsigned int cur_size, unsigned int new_size);
void cmd_args(char **args, shell_type *mytype, char *buffer);
int check_builtin(shell_type *mytype, char **args);
int find_sysfuncs(shell_type *mytype, char **args);
void exit_bin(shell_type *mytype, char **args);
void env_bin(shell_type *mytype, char **args);
int executable(char *file);
int File(char *filename);
int current_dir(char *commandd, char **args, char *buffer, shell_type *mytype);
char *Find_dir(char *directory, shell_type *mytype);
int print_error(char *msg);
int print_err(char *msge);
void moreErr_info(shell_type *mytype, char *moreErr);
void handle_err(shell_type *mytype);
void runn(shell_type *mytype);
char *_env(const char *varr);
void all_env(void);
void _pattern(shell_type *mytype, char **arggs);
char *process_pattern(shell_type *mytype, char *str);
int number_search(unsigned int X);
int letter_search(char *str);
char **tokenization(char *str, const char *delimm);
char *Fusion(char *Fst, char *Snd, char *Trd, const char *delimm);
char *error_message(shell_type mytype);
int num_count(int number);
int exit_binSupport(shell_type *mytype, char *arggg);
char *replace_env(shell_type *mytype, char *var);
char *replace_value(shell_type *mytype, int *pos, char *str);
char *sub(shell_type *mytype, int *input, char *word);
char *serialization(int numm);
void _path(char *pathh, shell_type *mytype);
int _atoi(char *str);
void exec_child(char *cmd, char **ar, shell_type *mytype, char *buffer);

#endif
