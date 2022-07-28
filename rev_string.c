#include "shell.h"

/**
* main - entry point
* Desc: program that accepts a string and reverses it
* Return: Always success (0)
*/

int main(void)
{
	char s[10] = "My School";

	printf("%s\n", s);
	rev_string(s);
	printf("%s\n", s);
	return (0);
}

/**
* rev_string - function reverses a string input
* @s: pointer to a string
* Return: void
*/

void rev_string(char *s)
{
	int length, i;
	char temp;

	for (length = 0; s[length] != '\0'; length++)

	i = 0;

	while (i < length--)
	{
		temp = s[i];
		s[i++] = s[length];
		s[length] = temp;
	}
}
