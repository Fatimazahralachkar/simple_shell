#include "header.h"

/**
 * ignore_ctrl_C - ignores Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ignore_ctrl_C(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * exit_if_ctrl_D - exits program if Ctrl-D is pressed
 * @read_char: characters read via read_cmd
 * @command: user's typed in command
 * @env: environmental variable linked list
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void exit_if_ctrl_D(int read_char, char *command, list_t *env)
{
	if (read_char == 0)
	{
		free(command);
		free_linked_list(env);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * ignore_space - return string without spaces in front
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * handling_built_in - handles builtins (exit, env, cd)
 * @token: user's typed command
 * @env: environmental variable
 * @num: take in nth user command typed to write error message
 * @command: bring in command to free
 * Return: 1 if acted on builtin, 0 if not
 */
int handling_built_in(char **token, list_t *env, int num, char **command)
{
	int i = 0;

	if (custom_strcmp(token[0], "cd") == 0)
	{
		i = cd_cmd(token, env, num);
	}

	else if (custom_strcmp(token[0], "exit") == 0)
	{
		i = exit_program(token, env, num, command);
	}

	else if (custom_strcmp(token[0], "env") == 0)
	{
		print_env(token, env);
		i = 1;
	}

	else if (custom_strcmp(token[0], "setenv") == 0)
	{
		custom_setenv(&env, token);
		i = 1;
	}
	else if (custom_strcmp(token[0], "unsetenv") == 0)
	{
		custom_unsetenv(&env, token);
		i = 1;
	}
	return (i);
}

