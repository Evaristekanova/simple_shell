#include "shell.h"

/**
* _realloc - reallocates a memory block using malloc and free
* @ptr: pointer to the memory previously allocated
* @old_size: size, in bytes, of the allocated space
* @new_size: new size, in bytes of the new memory block
* Return: ptr (if new_size == old_size),
* NULL (if new_size == 0 and ptr is not NULL)
* Otherwise - a pointer to the reallocated memory block
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *_nptr = NULL;
	char *_optr = ptr;
	unsigned int i = 0;

	if (old_size == new_size)
	{
		return (_optr);
	}
	if (_optr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(_optr);
		return (NULL);
	}

	_nptr = malloc(new_size);
	if (_nptr == NULL)
	{
		free(_optr);
		return (NULL);
	}

	while (i < old_size && i < new_size)
	{
		_nptr[i] = _optr[i];
	}

	free(_optr);
	return (_nptr);
}
