# include "shell.h"

/**
* _strcmp - compares two strings
* @s1: pointer to first string for comparison
* @s2: pointer to second string for comparison
* Return: 0 (if s1 == s2), -ve int (if s1 < s2), +ve int (if s1 > s2)
*/

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (s1[i] - s2[i]);

	return (0);
}
