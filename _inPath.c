#include "shell.h"

/**
 * _inPath - looks in paths for a function to be valid
 * @token: token to be looked in the PATH directories
 * Return: newly allocated string with PATH_found/token (if token is found in
 * PATH, NULL (if not found)
 */

char *_inPath(char **token)
{
	int file_stat, i;
	struct stat file_info;
	char *full_path = NULL, *tmp = NULL, **paths = NULL;

	if (_strchr(*token, '/') != 0)
		return (NULL);
	paths = _paths();
	if (paths == NULL)
		return (NULL);

	for (i = 0; paths[i] != NULL; i++)
	{
		full_path = concat(paths[i], "/");

		tmp = full_path;
		full_path = concat(full_path, *token);

		free(tmp);
		file_stat = stat(full_path, &file_info);
		if (file_stat == 0)
			break;

		free(full_path);
	}
	if (paths[i] == NULL)
	{
		free(paths[0] - 5);
		free(paths);
		return (NULL);
	}
	*token = full_path;
	free(paths[0] - 5);
	free(paths);
	return (full_path);
}
