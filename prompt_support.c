#include "shell.h"
/**
 * infinity_Prompt - Main loop of the prompt
 *
 * @mytype: Defined Struct
 *
 * Return: Buffer recieved from stdin
 **/
void infinityPrompt(shell_type *mytype)
{
	char *buffer, **args, *env_path;

	signal(SIGINT, sigint_handler);
	while (1)
	{
		prompt_info(mytype);

		env_path = getEnv("PATH");
		// isCurrPath(env_path, mytype);

		mytype->env = env_path;
		// buffer = parse_prompt();
		if (buffer == NULL)
		{
			_printor(mytype->current_mode == 1 ? "exit\n" : "");
			free(env_path);
			break;
		}
		mytype->cmd_num++;
		if (buffer[0] != '\n')
		{
			// args = tokenize_words(buffer, " \t\n");

			mytype->argss = args;
			mytype->buff = buffer;
			// patternAnalysis(mytype, args);
			cmd_args(args, mytype, buffer);

			free_doublepointer((void *) args);
		}
		free_pointer((void *) buffer);
		free_pointer((void *) env_path);
	}
}

/**
 * parse_prompt - uses the getline function to parse the input
 * And handle the end of file
 *
 * Return: Buffer input or NULL after freeing the read prompt if EOF
 **/
char *parse_prompt(void)
{
	char *buffer = NULL;
	int i;
	size_t size;

	// i = getline(&buffer, &size, stdin);

	if (i == EOF)
	{
		free_pointer((void *) buffer);
		return (NULL);
	}

	return (buffer);
}
