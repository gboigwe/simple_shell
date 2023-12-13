#include "shell.h"
/**
 * _strcat - Joins two strings together
 * @dest: The destination receiver
 * @src: The transmitter source
 *
 * Return: The destination is returned
 */
char *_strcat(char *dest, char *src)
{
	int dest_n, src_m;

	for (dest_n = 0; dest[dest_n] != '\0'; dest_n++)
		;
	for (src_m = 0; src[src_m] != '\0'; src_m++)
	{
		dest[dest_n] = src[src_m];
		dest_n++;
	}
	return (dest);
}
