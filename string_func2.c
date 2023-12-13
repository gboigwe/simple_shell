#include "shell.h"
/**
 * _isalpha - CThis function will check for alphabet
 * @c: The variable parameter
 *
 * Return: 0 on Success
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
/**
 * opp_arr - Array will be reversed in this function
 * @arr: Variable array considered
 * @len: Variable length considered
 *
 * Return: void array reversed
 */
void opp_arr(char *arr, int len)
{
	int index;
	char temp;

	for (index = 0; index < (len / 2); index++)
	{
		temp = arr[index];
		arr[index] = arr[(len - 1) - index];
		arr[(len - 1) - index] = temp;
	}
}
/**
 * _itochar - This func changes int to char
 * @n: The variable parameter considered
 *
 * Return: char
 */
char *_itochar(unsigned int n)
{
	int num = 0, index = 0;
	char *str;

	num = numslen(n);
	str = malloc(num + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	while (n / 10)
	{
		str[index] = (n % 10) + '0';
		n /= 10;
		index++;
	}
	str[index] = (n % 10) + '0';
	opp_arr(str, num);
	str[index + 1] = '\0';
	return (str);
}
/**
 * numslen - Number the length of the int
 * @num: Variable tobe checked
 * Return: Length number
 */
int numslen(int num)
{
	int nums = 0;

	while (num != 0)
	{
		nums++;
		num /= 10;
	}
	return (nums);
}
