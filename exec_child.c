#include "shell.h"

/**
 * exec_child - executes a command in a child process
 * @cmds: NULL terminated pointer array to the command and flags
 * @av: string with the name of the executable
 * @count: a summation of errors
 * Return: Always success (0)
 */

void exec_child(char **cmds, char *av, int count)
{
	if (execve(cmds[0], cmds, environ) == -1)
	{
		write(STDERR_FILENO, av, _strlen(argv));
		write(STDERR_FILENO, ": ", 2);
		_printnumber(count);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmds[0], _strlen(cmds[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		exit(EXIT_FAILURE);
	}
}
