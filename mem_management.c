#include "shell.h"

/**
 *mem_realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer
 * @old_size: Previous size of the pointer
 * @new_size: New size of the pointer
 *
 * Return: Void pointer to the reallocated memory
 */
void *mem_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	result = malloc(new_size);
	if (result == NULL)
		return (NULL);

	if (ptr == NULL)
	{
		fill_array(result, '\0', new_size);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}

	return (result);
}

/**
 * free_array - Free array of char pointers and char pointer
 * @cmd: Array pointer
 * @line: Char pointer
 *
 * Return: Void
 */
void free_array(char **cmd, char *line)
{
	free(cmd);
	free(line);
}

/**
 * _memcpy - Copy byte from source to destination
 * @dest: Destination pointer
 * @src: Source pointer
 * @n: Size (how much you will copy)
 *
 * Return: Void pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_array - Fill an array by constant byte
 * @a: Void pointer
 * @el: Int
 * @len: Length int
 *
 * Return: Void pointer
 */
void *fill_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc - Allocates memory for an array, using malloc
 * @size: Size
 *
 * Return: Void pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);

	a = malloc(size);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
