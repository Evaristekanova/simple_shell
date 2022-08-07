#include "shell.h"

/**
 * built_ins - checks if token belongs to any built-in function, frees any
 * necessary allocated memory before exit
 * @buffer: allocated string from which commands are obtaned
 * @token: token to be checked as a built-in
 * Return: 1 (if a valid built-in is found), 0 (if it fails)
 */

int built_ins(char *buffer, char *token)
{
	if ((_strcmp("exit", token)) == 0)
	{
		free(buffer);
		exit(0);
	}
	else if ((_strcmp("env", token)) == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}
