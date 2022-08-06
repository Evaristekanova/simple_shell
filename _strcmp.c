# include "shell.h"

/**
* _strcmp - compares two strings
* @s1: pointer to first string for comparison
* @s2: pointer to second string for comparison
* Return: 0 (if s1 == s2), -ve int (if s1 < s2), +ve int (if s1 > s2)
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}
