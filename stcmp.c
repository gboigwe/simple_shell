#include "shell.h"
/**
 * _strcmp - Compares two strings
 * @str1: first srting of comparation
 * @str2: second string of comparatio
 *
 * Return: 0 Always
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
	}
	return (str1 - str2);
}
