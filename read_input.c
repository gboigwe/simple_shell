#include "shell.h"
/**
 * _readinput - Read the input by user from stdin
 *
 * Return: Input string or NULL on failure
 */
char *_readinput()
{
	int i, buffsize = BUFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		perror("malloc error");
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}

		buff[i] = c;

		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = mem_realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				perror("realloc error");
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	_hashtag(buff);
	return (buff);
}
/**
 * _hashtag - Remove everything after #
 * @buff: Input string
 *
 * Return: void
 */
void _hashtag(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
