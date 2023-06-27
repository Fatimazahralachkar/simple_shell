#include "header.h"

/**
 * exec_cmd - execute command user typed into shell
 * @s: command user typed
 * @env: environmental variable
 * @num: nth user command to be used in error message
 * Owned by: Imane & Fatima Zahra
 * Return: 0 on success
 */
int exec_cmd(char **s, list_t *env, int num)
{
	pid_t pid;
	char *holder;
	int status = 0, t = 0;

	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}
	else
		holder = cmd_path(s[0], env);
	if (access(holder, X_OK) != 0)
	{
		print_not_found_error(s[0], num, env);
		deallocate_strings(s);
		return (127);
	}

	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(holder, s, NULL) == -1)
			{
				print_not_found_error(s[0], num, env);
				free_cmd(s, env);
			}
		}
		else
		{
			wait(&status);
			deallocate_strings(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}

/**
 * free_cmd - frees user's typed command and linked list before exiting
 * @str: user's typed command
 * @env: input the linked list of envirnment
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void free_cmd(char **str, list_t *env)
{
	deallocate_strings(str);
	free_linked_list(env);
	_exit(0);
}


/**
 *  handle_piped_cmd- handles when user pipes commands into shell via pipeline
 * (e.g. echo "ls/nls -al/n" | ./a.out)
 * @env: envrionmental variables
 */
void handle_piped_cmd(list_t *env)
{
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	i = read_command(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = str_tokenize(command, "\n");
	if (n_command != NULL)
		free(n_command);
	n = 0;
	while (n_line[n] != NULL)
	{
		command_line_no++;
		token = NULL;
		token = str_tokenize(n_line[n], " ");
		exit_stat = handling_built_in(token, env, command_line_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = exec_cmd(token, env, command_line_no);
		n++;
	}
	deallocate_strings(n_line);
	free_linked_list(env);
	exit(exit_stat);
}

/**
 * cmd_path - searchs through path directories for full path
 * @str: first command user typed into shell
 * @env: environmental variable
 * Return: a copy of fleshed out command
 */
char *cmd_path(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;

	pth = get_env("PATH", env);
	toks = custom_str_tokenize(pth, ":");
	free(pth);

	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = custom_strdup(toks[i]);
		cat = custom_strcat(cat, "/");
		cat = custom_strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			deallocate_strings(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	deallocate_strings(toks);
	return (str);
}

