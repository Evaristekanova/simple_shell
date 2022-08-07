#include "shell.h"

/**
 * _interpiped - runs non interactive shell when input is piped.
 * @av: name of the program.
 * Return: Always success (0)
 */

int _interpiped(char *av)
{
	char **cmds = NULL, *buffer = NULL, *token = NULL;
	char *heap_token = NULL;
	size_t size = 0;
	pid_t child_pid;
	int status, error = 0, count = 1;

	while ((getline(&buffer, &size, stdin)) != -1)
	{
		token = strtok(buffer, " \n\t\r");
		if (token != NULL)
		{
			if (built_ins(buffer, token) == 1)
				continue;
			heap_token = _inPath(&token);
			cmds = _tokenparser(token, buffer);
			child_pid = fork();
			if (child_pid == 0)
			{
				exec_child(cmds, av, count);
			}
			else
			{
				waitpid(child_pid, &status, 0);
				error = WEXITSTATUS(status);
			}
			free_all(buffer, cmds, heap_token);
			size = 0;
		}
		count++;
	}
	if (size != 0)
		free(buffer);
	return (error);
}
