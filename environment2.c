#include "header.h"

/**
 * my_setenv - custom _setenv by concatenating string first before setting
 * @env: environmental variable linked list
 * @name: environmental variable name (e.g. "OLDPWD")
 * @dir: directory path (e.g. "/home/vagrant/directory1")
 * Return: 0 on success (e.g. "OLDPWD=/home/vagrant/directory1")
 */
int my_setenv(list_t **env, const char *name, const char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	cat = custom_strdup(name);
	cat = custom_strcat(cat, "=");
	cat = custom_strcat(cat, dir);
	index = find_env(*env, name);

	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = custom_strdup(cat);
	free(cat);
	return (0);
}

/**
 * c_ignore - custom ignores spaces and newlines
 * (e.g. echo "ls\n ls" | ./a.out)
 * @str: envrionmental variables
 * Return: new string
 */
char *c_ignore(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

