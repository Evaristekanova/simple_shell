#include "shell.h"

/**
* _shell - opens a session of the interactive shell
* Return: Always success (0)
*/

int _shell(void)
{
	size_t line_size  = 0;
	ssize_t line = 0;
	char *buffer = NULL;
	int error = 0, count = 1;

	write(STDOUT_FILENO, "shell~$ ", 10);
	while ((line = getline(&buffer, &line_size, stdin)))
	{
		if (line == EOF)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		if (*buffer == '\n')
		{
			write(STDOUT_FILENO, "shellby~$ ", 10);
			count++;
			continue;
		}

		error = _getlineprocess(&buffer, &line_size, &count);
		write(STDOUT_FILENO, "shell~$ ", 10);
	}
	return (error);
}
