#include "header.h"

/**
 * print_not_found_error - prints the "not found" error message
 * @command: user's typed command
 * @command_number: nth user's typed command
 * @env: environmental variables linked list to retrieve shell name
 */
void print_not_found_error(char *command, int command_number, list_t *env)
{
	int count = 0;
	char *shell_name, *command_num_str;

	shell_name = get_env("_", env);
	while (shell_name[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell_name, count);
	free(shell_name);
	write(STDOUT_FILENO, ": ", 2);
	command_num_str = custom_int_to_string(command_number);
	count = 0;
	while (command_num_str[count] != '\0')
		count++;
	write(STDOUT_FILENO, command_num_str, count);
	free(command_num_str);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (command[count] != '\0')
		count++;
	write(STDOUT_FILENO, command, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}


/**
 * print_cd_error - prints the "can't cd to" error message
 * @directory: directory argument after the cd command
 * @command_number: nth user's typed command
 * @env: environmental variables linked list to retrieve shell name
 */
void print_cd_error(char *directory, int command_number, list_t *env)
{
	int count = 0;
	char *shell_name, *command_num_str;

	shell_name = get_env("_", env);
	while (shell_name[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell_name, count);
	free(shell_name);
	write(STDOUT_FILENO, ": ", 2);
	command_num_str = custom_int_to_string(command_number);
	count = 0;
	while (command_num_str[count] != '\0')
		count++;
	write(STDOUT_FILENO, command_num_str, count);
	free(command_num_str);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	count = 0;
	while (directory[count] != '\0')
		count++;
	write(STDOUT_FILENO, directory, count);
	write(STDOUT_FILENO, "\n", 1);
}


/**
 * print_illegal_number_error - prints the "Illegal number"
 *				error message for exit command
 * @number: user's typed argument after the exit command
 * @command_number: nth user's typed command
 * @env: environmental variables linked list to retrieve shell name
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void print_illegal_number_error(char *number, int command_number, list_t *env)
{
	int count = 0;
	char *shell_name, *command_num_str;

	shell_name = get_env("_", env);
	while (shell_name[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell_name, count);
	free(shell_name);
	write(STDOUT_FILENO, ": ", 2);
	command_num_str = custom_int_to_string(command_number);
	count = 0;
	while (command_num_str[count] != '\0')
		count++;
	write(STDOUT_FILENO, command_num_str, count);
	free(command_num_str);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number: ", 22);
	count = 0;
	while (number[count] != '\0')
		count++;
	write(STDOUT_FILENO, number, count);
	write(STDOUT_FILENO, "\n", 1);
}

