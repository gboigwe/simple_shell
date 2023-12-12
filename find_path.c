#include "shell.h"
/**
 * path_cmnd - Search In $PATH For Executable Command
 * @cmd: Parsed Input, and it will be updated with the full path if found
 *
 * Return: 0 on success, 1 on failure.
 */
int path_cmnd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	/* Get the value of the PATH environment variable */
	path = get_env("PATH");

	/* Tokenize the PATH variable to get each directory */
	value = _strtok(path, ":");
	while (value != NULL)
	{
		/* Build the full path by combining the directory and the command */
		cmd_path = build(*cmd, value);

		/* Check if the command exists in the current directory */
		if (stat(cmd_path, &buf) == 0)
		{
			/* Update the cmd with the full path of the executable */
			*cmd = _strdup(cmd_path);

			/* Free allocated memory and return success */
			free(cmd_path);
			free(path);
			return (0);
		}

		/* Free the memory allocated for cmd_path and move to the next directory */
		free(cmd_path);
		value = _strtok(NULL, ":");
	}

	/* Free the memory allocated for PATH and return failure */
	free(path);
	return (1);
}
/**
 * build - Build the full path of a command
 * @token: Executable command
 * @value: Directory containing the command
 *
 * Return: Parsed full path of the command or NULL in case of failure
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	/* Calculate the length needed for the full path */
	len = _strlen(value) + _strlen(token) + 2;

	/* Allocate memory for the full path */
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	/* Initialize the allocated memory to zero */
	memset(cmd, 0, len);

	/* Concatenate the directory, "/", and the token to build the full path */
	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * get_env - Get the value of an environment variable by name
 * @name: Environment variable name
 *
 * Return: The value of the environment variable or NULL if not found
 */
char *get_env(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	/* Calculate the length of the environment variable name */
	nl = _strlen(name);

	/* Iterate through the environment variables */
	for (i = 0; environ[i]; i++)
	{
		/* Check if the current environment variable matches the specified name */
		if (_strncmp(name, environ[i], nl) == 0)
		{
			/* Calculate the length of the value part of the environment variable */
			vl = _strlen(environ[i]) - nl;

			/* Allocate memory for the value */
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				perror("unable to allocate memory");
				return (NULL);
			}

			/* Copy the value part of the env variable to the allocated memory */
			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
