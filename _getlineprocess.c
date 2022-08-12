#include "shell.h"

/**
 * _getlineprocess - interprets line obtained by getline
 * @buffer: double pointer to the buffer obtained from getline
 * @line_size: pointer to the size of the buffer
 * @count: count of the number of lines executed in the shell
 * Return: error status on success (0)
 */

int _getlineprocess(char **buffer, size_t *line_size, int *count)
{
	char *token = NULL, **commands = NULL;
	char *token_o = NULL, *heap_token = NULL;
	int  status, error = 0;
	pid_t child_pid;

	token = strtok(*buffer, " \n\t\r");
	if (token != NULL)
	{
		if (built_ins(*buffer, token) == 1)
		{
			free(*buffer);
			*buffer = NULL;
			*line_size = 0;
			return (0);
		}
		token_o = token;
		heap_token = _inPath(&token);
		commands = _tokenparser(token, *buffer);
		if (commands == NULL)
			return (0);
		child_pid = fork();
		if (child_pid == 0)
			exec_child(commands, token_o, *count);
		else if (child_pid == -1)
		{
			perror("Error");
			exit(1);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				error = WEXITSTATUS(status);
		}
		free_all(*buffer, commands, heap_token);
		*line_size = 0;
		*buffer = NULL;
	}
	(*count)++;
	return (error);
}
