#include "shell.h"
/**
 * numprint_func - Print out the unsigned integer
 * @n: The variable to be considered
 *
 * Return: Void to print
 */
void numprint_func(unsigned int n)
{
	unsigned int index = n;

	if ((index / 10) > 0)
	{
		numprint_func(index / 10);
	}
	_putchar(index % 10 + '0');
}
/**
 * numprintin_func - Print number with putchar
 * @n: The variable to be considered for num printing
 *
 * Return: Void to print
 */
void numprintin_func(int n)
{
	unsigned int index = n;

	if (n < 0)
	{
		_putchar('-');
		index = -index;
	}
	if ((index / 10) > 0)
		numprint_func(index / 10);

	_putchar(index % 10 + '0');
}
