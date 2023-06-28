#include "foufa_simple.h"

/**
* _pathfind - finds local path search
* Owned by: Imane & Fatima Zahra
* Return: NULL if the path is not detected, or is detected
*/

char *_pathfind(void)
{
	int x = 0;
	char **env = environ;
	char *path = NULL;

	while (*env)
	{
		if (_stringmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			int x = 0;

			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
