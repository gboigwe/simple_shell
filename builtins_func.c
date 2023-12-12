#include "shell.h"
/**
 * exit_func - Exit mode from shell state
 * @cmd: Command in processing state
 * @input: Variable that takes in command
 * @argv: Arg variable name
 * @c: Number of execute out
 * Return: Void exit will exit
 */
void exit_func(char **cmd, char *input, char **argv, int c)
{
	int exit_state, index = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][index])
	{
		if (_isalpha(cmd[1][index++]) != 0)
		{
			pr_error(argv, c, cmd);
			break;
		}
		else
		{
			exit_state = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(exit_state);
		}
	}
}
/**
 * dir_func - The function that changes directories
 * @cmd: Command in processing state
 * @er: State of the last command that was called
 * Return: 0 Success
 */
int dir_func(char **cmd, __attribute__((unused))int er)
{
	int data = -1;
	char cwd_path[PATH_MAX];

	if (cmd[1] == NULL)
		data = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		data = chdir(getenv("OLDPWD"));
	}
	else
		data = chdir(cmd[1]);

	if (data == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (data != -1)
	{
		getcwd(cwd_path, sizeof(cwd_path));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd_path, 1);
	}
	return (0);
}
/**
 * env_var - Function that displays the envr variable
 * @cmd: Command in processing state
 * @er: State of the last command that was called
 * Return:Always 0
 */
int env_var(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t index;
	int count;

	for (index = 0; environ[index] != NULL; index++)
	{
		count = _strlen(environ[index]);
		write(1, environ[index], count);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * help_call - Calling out help for built in func
 * @cmd: Command in processing state
 * @er: State of the last command that was called
 * Return: 0 Success
 */
int help_call(char **cmd, __attribute__((unused))int er)
{
	int file_doc, file_write, read_doc = 1;
	char c;

	file_doc = open(cmd[1], O_RDONLY);
	if (file_doc < 0)
	{
		perror("Error");
		return (0);
	}
	while (read_doc > 0)
	{
		read_doc = read(file_doc, &c, 1);
		file_write = write(STDOUT_FILENO, &c, read_doc);
		if (file_write < 0)
			return (-1);
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_func - Excute Echo Cases
 * @st: State of the last command that was called
 * @cmd: Command in processing state
 * Return: Always 0
 */
int echo_func(char **cmd, int st)
{
	char *echo_path;
	unsigned int  ppid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		numprintin_func(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		numprint_func(ppid);
		PRINTER("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		echo_path = get_env("PATH");
		PRINTER(echo_path);
		PRINTER("\n");
		free(echo_path);

	}
	else
		return (print_echo(cmd));

	return (1);
}
