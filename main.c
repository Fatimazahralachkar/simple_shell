#include "header.h"

/**
 * main - entry point of the simple_shell program
 * @argc: argument count
 * @argv: argument vectors
 * @envp: environmental variables
 * Owned by: Imane & Fatima Zahra
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	shell_prompt(envp);

	return (0);
}
