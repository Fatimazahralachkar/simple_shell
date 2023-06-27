#include "header.h"


/**
 * exit_program - frees resources then exits
 * @exit_cmd: user's command for exit
 * @env: environmental variables linked list
 * @cmd_num: nth user command line input
 * @cmd: command to be freed
 * Owned by: Imane & Fatima Zahra
 * Return: 0 if successful, 2 if failed
 */
int exit_program(char **exit_cmd, list_t *env, int cmd_num, char **cmd)
{
	int exit_value = 0;

	if (exit_cmd[1] != NULL)
		exit_value = custom_atoi(exit_cmd[1]);

	if (exit_value == -1)
	{
		print_illegal_number_error(exit_cmd[1], cmd_num, env);
		deallocate_strings(exit_cmd);
		return (2);
	}

	deallocate_strings(exit_cmd);
	free_linked_list(env);
	deallocate_strings(cmd);

	exit(exit_value);
}

