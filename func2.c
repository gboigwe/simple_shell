#include "shell.h"
/**
 * _strncpy - A number of string is copied
 * @dest: destined receiver
 * @src: source
 * @n: lenght of string to be considered
 *
 * Return: dest is returned
 */
char *_strncpy(char *dest, char *src, int n)
{
	int index;

	index = 0;
	while (index < n && *(src + index))
	{
		*(dest + index) = *(src + index);
		index++;
	}
	while (index < n)
	{
		*(dest + index) = '\0';
		index++;
	}
	return (dest);
}
/**
 * _strncmp - This function compare two strings in nth.
 * @s1: The first string considered
 * @s2: The second string cosidered
 * @n: The nth amount comparism.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	if (s1 == NULL)
		return (-1);
	for (index = 0; index < n && s2[index]; index++)
	{
		if (s1[index] != s2[index])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - This function duplicates string
 * @str: The string considered for duplicate
 *
 * Return: Duplicate is returned
 */
char *_strdup(char *str)
{
	size_t num, index;
	char *str2;

	num = _strlen(str);
	str2 = malloc(sizeof(char) * (num + 1));
	if (!str2)
		return (NULL);
	for (index = 0; index <= num; index++)
	{
		str2[index] = str[index];
	}
	return (str2);
}
/**
 * _strchr - Location of string
 * @s: Variable string searcher
 * @c: Variable char searcher
 *
 * Return: if found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}
