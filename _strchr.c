#include "shell.h"

/**
* _strchr - locates a character in a string
* @s: string to be scanned
* @c: character being located in string
* Return: a pointer to first occurrence of character in string
* NULL (if the character is not found)
*/

char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}
	if (*s == c)
	{
		return (s);
	}
	return (NULL);
}
