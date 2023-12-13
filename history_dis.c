#include "shell.h"

/**
 * display_hist - Display history of user input in Simple Shell
 * @c: Parsed command (unused)
 * @s: Status of the last execution (unused)
 *
 * Return: 0 on success, -1 on failure
 */
int display_hist(__attribute__((unused)) char **c, __attribute__((unused)) int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return (-1);
	}

	while (getline(&line, &len, fp) != -1)
	{
		counter++;
		er = _itochar(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);
	}

	if (line)
		free(line);

	fclose(fp);
	return (0);
}

/**
 * print_echo - Execute normal echo
 * @cmd: Parsed command
 *
 * Return: 0 on success, -1 on failure
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork error");
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
