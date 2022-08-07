#include "shell.h"

/**
 * _tokenparser - finds and allocates tokens in a buffer
 * @token: first token to be allocated
 * @buffer: buffer being tokenized
 * Return: address of allocated pointers, NULL (if it fails)
 */

char **_tokenparser(char *token, char *buffer)
{
	char **cmds = NULL;
	size_t cmdsize = 0;
	int i = 0, last = 0;

	cmds = _realloc(cmds, cmdsize, cmdsize + sizeof(char *));
	if (cmds == NULL)
	{
		free(cmds);
		return (NULL);
	}
	cmd_size += sizeof(char *);
	cmds[i++] = token;
	last = _strlen(buffer) + 1;
	token = strtok(buffer + last, " \n\t\r");
	while (token != NULL)
	{
		cmds = _realloc(cmds, cmdsize, cmdsize + sizeof(char *));
		if (cmds == NULL)
		{
			free(cmds);
			return (NULL);
		}
		cmdsize += sizeof(char *);
		cmds[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	cmds = _realloc(cmds, cmdsize, cmdsize + sizeof(char *));
	if (cmds == NULL)
	{	free(cmds);
		return (NULL);
	}
	cmdsize += sizeof(char *);
	cmds[i] = NULL;
	return (cmds);
}
