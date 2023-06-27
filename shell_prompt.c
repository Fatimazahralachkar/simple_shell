#include "header.h"

/**
 * shell_prompt - repeatedly prompts user and executes user's cmd
 * @en: envrionmental variables
 * Owned by: Imane & Fatima Zahra
 * Return: 0 on success
 */
int shell_prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			handle_piped_cmd(env);
		signal(SIGINT, ignore_ctrl_C);
		command = NULL;
		i = 0;
		i = read_command(&command);
		exit_if_ctrl_D(i, command, env);
		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = str_tokenize(command, " ");
		if (n_command != NULL)
			free(n_command);
		exit_stat = handling_built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = exec_cmd(token, env, command_line_no);
	} while (1);
	return (exit_stat);
}

