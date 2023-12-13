#include "shell.h"
/**
 * delim_checker - checks the start or stop of a char
 * @c: The character that is considered
 * @s: The string that is considered
 *
 * Return: 1 success
 */
unsigned int delim_checker(char c, const char *s)
{
	unsigned int index;

	for (index = 0; s[index] != '\0'; index++)
	{
		if (c == s[index])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strtok - extracts tokens from a string
 * @str: The string to be considered
 * @delim: monitors a character
 *
 * Return: continue to next token if Null
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_start, *token_end;
	unsigned int index;

	if (str != NULL)
	{
		token_end = str;
	}
	token_start = token_end;
	if (token_start == NULL)
		return (NULL);
	for (index = 0; token_start[index] != '\0'; index++)
	{
		if (delim_checker(token_start[index], delim) == 0)
			break;
	}
	if (token_end[index] == '\0' || token_end[index] == '#')
	{
		token_end = NULL;
		return (NULL);
	}
	token_start = token_end + index;
	token_end = token_start;
	for (index = 0; token_end[index] != '\0'; index++)
	{
		if (delim_checker(token_end[index], delim) == 1)
			break;
	}
	if (token_end[index] == '\0')
		token_end = NULL;
	else
	{
		token_end[index] = '\0';
		token_end = token_end + index + 1;
		if (*token_end == '\0')
			token_end = NULL;
	}
	return (token_start);
}
