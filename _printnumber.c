#include "shell.h"

/**
 * _printnumber - prints an integer
 * @n: input number to be printed
 * Return: Always success (0)
 */

void _printnumber(int n)
{
	int result = n, flag = 1;
	char digit = '0';

	while (res / 10)
	{
		flag *= 10;
		result /= 10;
	}
	while (flag)
	{
		result = n / flag;
		digit = result + '0';
		write(STDERR_FILENO, &digit, 1);
		n = n - (result * flag);
		flag /= 10;
	}
}
