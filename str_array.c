#include "shell.h"

/**
* str_array - function that splits string entered by user
* @buffer: the string to be split
* Return: the sub-strings of the split string
*/

char **str_array(char *buffer)
{
	char **commands = NULL;
	char *token, *delimeter = " \n";
	int i;

	commands = malloc(sizeof(char *) * bufsize);
	if (commands == NULL)
	{
		perror("memory could not be allocated");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delimeter);
	i = 0;
	while (token != NULL)
	{
		commands[i] = token;
		token = strtok(NULL, delimeter);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
