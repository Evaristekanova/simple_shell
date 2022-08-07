#include "shell.h"

/**
 * print_env - prints environment variables
 * Return: void
 */

void print_env(void)
{
	unsigned int  i, length;

	if (environ == NULL || *environ[0] == '\0')
		return;

	for (i = 0; environ[i] != NULL; i++)
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
