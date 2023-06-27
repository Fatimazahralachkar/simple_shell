#include "header.h"

/**
 * cd_home - changes directory to home
 * @env_list: bring in environmental linked list to update PATH and OLDPWD
 * @current_dir: bring in current working directory
 * Owned by: Imane and Fatima Zahra
 * Return: void
 */
void cd_home(list_t *env_list, char *current_dir)
{
	char *home_dir = NULL;

	home_dir = get_env("HOME", env_list);
	my_setenv(&env_list, "OLDPWD", current_dir);
	free(current_dir);
	if (access(home_dir, F_OK) == 0)
		chdir(home_dir);
	current_dir = NULL;
	current_dir = getcwd(current_dir, 0);
	my_setenv(&env_list, "PWD", current_dir);
	free(current_dir);
	free(home_dir);
}
/**
 * cd_execute - executes the cd
 * @env_list: bring in environmental linked list to update PATH and OLDPWD
 * @dir: bring in current working directory
 * @dirpath: bring in directory path to change to
 * @a: bring in the 1st argument to write out error
 * @nline: bring in the line number to write out error
 * Owned by: Imane & Fatima Zahra
 * Return: 0 if success, 2 if fail
 */
int cd_execute(list_t *env_list, char *dir, char *dirpath, char *a, int nline)
{
	int status = 0;

	if (access(dirpath, F_OK) == 0)
	{
		my_setenv(&env_list, "OLDPWD", dir);
		free(dir);
		chdir(dirpath);
		dir = NULL;
		dir = getcwd(dir, 0);
		my_setenv(&env_list, "PWD", dir);
		free(dir);
	}
	else
	{
		print_cd_error(a, nline, env_list);
		free(dir);
		status = 2;
	}
	return (status);
}


/**
 * cd_cmd - change directory
 * @str: user's typed in command
 * @env: enviromental linked list to retrieve HOME and OLDPWD paths
 * @num: nth user command, to be used at error message
 * Owned by: Imane & Fatima Zahra
 * Return: 0 if success 2 if failed
 */
int cd_cmd(char **str, list_t *env, int num)
{
	char *current = NULL, *dir = NULL;
	int exit_stat = 0;

	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			dir = get_env("HOME", env);
			dir = custom_ignore_first_c_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = custom_strcat(dir, "/");
				dir = custom_strcat(dir, str[1]);
			}
			else
				dir = custom_strdup(str[1]);
		}
		exit_stat = cd_execute(env, current, dir, str[1], num);
		free(dir);
	}
	else
		cd_home(env, current);
	deallocate_strings(str);
	return (exit_stat);
}

