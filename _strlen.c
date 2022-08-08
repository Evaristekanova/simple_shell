# include "shell.h"

/**
* _strlen - returns the length of a string
* @s: pointer to a char
* Return: integer length of string at address
*/

unsigned int _strlen(const char *s)
{
	int slen = 0;

	while (s[slen] != '\0')
	{
		slen++;
	}
	return (slen);
}
