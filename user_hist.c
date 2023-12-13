#include "shell.h"
/**
 * hist - Write user input to a file
 * @input: User input
 *
 * Return: -1 on failure, 0 on success
 */
int hist(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
	{
		perror("open error");
		return (-1);
	}

	if (input)
	{
		while (input[len])
			len++;

		w = write(fd, input, len);
		if (w < 0)
		{
			perror("write error");
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (0);
}
/**
 * env_done - Free environment variable array
 * @env: Environment variables.
 *
 * Return: void
 */
void env_done(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}

	/* Free the array itself */
	free(env);
}
