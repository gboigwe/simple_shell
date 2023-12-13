#include "shell.h"
/**
 * _putchar - writes the character c into stdout
 * @c: The character to be considered
 *
 * Return: on success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strcpy - Function that copies char to a different
 * @dest: Varible dest to be considered
 * @src: The source considered
 * Return: Copied char
 */
char *_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
/**
 * _strlen - Counts the number of strings
 * @s: String to be considered
 * Return: 0 Always
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
/**
 * _atoi - converts a string to an integer
 * @s: The string to be considered
 *
 * Return: value of integer is returned
 */
int _atoi(char *s)
{
	int i_index, j_index, n_index, m_index;

	i_index = n_index = 0;
	m_index = 1;
	while ((s[i_index] < '0' || s[i_index] > '9') && (s[i_index] != '\0'))
	{
		if (s[i_index] == '-')
			m_index *= -1;
		i_index++;
	}
	j_index = i_index;
	while ((s[j_index] >= '0') && (s[j_index] <= '9'))
	{
		n_index = (n_index * 10) + m_index * ((s[j_index]) - '0');
		j_index++;
	}
	return (n_index);
}
/**
* _puts - prints out a string
* @str: The string to be considered
*
* Return: void
*/
void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
