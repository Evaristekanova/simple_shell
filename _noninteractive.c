#include "shell.h"

/**
 * _noninteractive - a session of non-interactive shell
 * @ac: number of input arguments
 * @av: NULL terminated array of input arguments
 * Return: Always success (0)
 */

int _noninteractive(int ac, char *av[])
{
	char *args_temp[2] = {NULL, NULL};
	int acce = 0, error = 0;

	if (ac > 1)
	{
		args_temp[0] = av[1];
		acce = access(av[1], R_OK);
		if (acce == 0)
			exec_child(args_temp, av[0], 1);
	}
	else
	{
		error = _interpiped(av[0]);
	}
	return (error);
}
