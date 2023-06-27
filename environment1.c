#include "header.h"

/**
 * print_env - prints environmental variables
 * @str: user's command into shell (i.e. "env")
 * @env: environmental variables
 * Return: 0 on success
 */
int print_env(char **str, list_t *env)
{
	deallocate_strings(str); /* frees user input */
	print_linked_list(env); /* prints env */
	return (0);
}



/**
 * get_env - finds and returns a copy of the requested environmental variable
 * @str: string to store it in
 * @env: entire set of environmental variables
 * Owned by: Imane & Fatima Zahra
 * Return: copy of requested environmental variable
 */
char *get_env(char *str, list_t *env)
{
	int j = 0, exclude_bytes = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (str[exclude_bytes] != '\0')
		exclude_bytes++;
	exclude_bytes++;
	return (custom_strdup_ebb(env->var, exclude_bytes));
}



/**
 * find_env - find given environmental variable in linked list
 * @env: environmental variable linked list
 * @str: variable name
 * Owned by: Imane & Fatima Zahra
 * Return: index of node in linked list
 */
int find_env(list_t *env, const char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		while ((env->var)[j] == str[j])
		{
			if (str[j] == '\0')
				return (index);
			j++;
		}
		env = env->next;
		index++;
	}

	return (-1);
}

/**
 * custom_setenv - creates or modify environmental variable in linked list
 * @env: linked list
 * @str: user's typed in command
 * Owned by: Imane & Fatima Zahra
 * Return: 0 on success, 1 on fail
 */
int custom_setenv(list_t **env, char **str)
{
	int index = 0, j = 0;
	char *new_var;
	list_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		deallocate_strings(str);
		return (1);
	}
	new_var = custom_strdup(str[1]);
	new_var = custom_strcat(new_var, "=");
	new_var = custom_strcat(new_var, str[2]);
	index = find_env(*env, str[1]);
	if (index == -1)
	{
		add_node_at_end(env, new_var);
	}
	else
	{
		holder = *env;
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		free(holder->var);
		holder->var = custom_strdup(new_var);
	}
	free(new_var);
	deallocate_strings(str);
	return (0);
}


/**
 * custom_unsetenv - remove node in environmental linked list
 * @env: linked list
 * @str: user's typed in command
 * Owend by: Imane & Fatima Zahra
 * Return: 0 on success
 */
int custom_unsetenv(list_t **env, char **str)
{
	int index = 0, j = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		deallocate_strings(str);
		return (1);
	}
	index = find_env(*env, str[1]);
	deallocate_strings(str);
	if (index == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (1);
	}
	j = delete_node_at_index(env, index);
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (1);
	}
	return (0);
}

