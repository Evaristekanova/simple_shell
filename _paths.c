#include "shell.h"

/**
 * _paths - searches for PATH in env and returns a newly allocated array of
 * strings with the directories in PATH
 * Return: newly allocated array of strings with all the directories in PATH
 */

char **_paths(void)
{
	int i = 0;
	char *token = NULL, *path_dup = NULL, **paths = NULL;
	size_t path_size = 0;

	if (environ == NULL || environ[i] == NULL)
		return (NULL);
	while (environ[i++] != NULL)
		if (_strncmp((const char *)environ[i], "PATH=", 5) == 0)
			break;
	if (environ[i] == NULL)
		return (NULL);
	path_dup = malloc(_strlen(environ[i]) + 1);
	if (path_c == NULL)
		return (NULL);
	path_dup = _strcpy(path_dup, environ[i]);
	token = strtok(path_dup, "=");
	i = 0;
	token = strtok(NULL, ":\n");
	while (token != NULL)
	{
		paths = _realloc(paths, path_size, path_size + sizeof(char *));
		if (paths == NULL)
		{
			free(path_dup);
			return (NULL);
		}
		path_size += sizeof(char *);
		paths[i++] = token;
		token = strtok(NULL, ":\n");
	}
	paths = _realloc(paths, path_size, path_size + sizeof(char *));
	if (paths == NULL)
	{
		free(path_dup);
		return (NULL);
	}
	path_size += sizeof(char *);
	paths[i] = NULL;
	return (paths);
}
