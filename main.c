#include "shell.h"

/**
 * main - entry point for execution of shell
 * @ac: number of input arguments.
 * @av: input arguments array.
 *
 * Return: 0 on success.
 */

int main(int ac, char *av[])
{

	if (isatty(STDIN_FILENO) != 1 || ac > 1)
	{
		_noninteractive(ac, av);
	}
	else
	{
		_shell();
	}

	exit(0);
	return (0);
}
