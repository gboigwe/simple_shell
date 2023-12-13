#include "shell.h"
/**
 * builtins_handler - This function handles builtin command
 * @cmd: Command in processing state
 * @er: State of the last command that was called
 *
 * Return: 0 Success upon execute
 */
int builtins_handler(char **cmd, int er)
{
	bul_t bl_deck[] = {
		{"cd", dir_func},
		{"env", env_var},
		{"help", help_call},
		{"echo", echo_func},
		{"history", display_hist},
		{NULL, NULL}
	};
	int index = 0;

	while ((bl_deck + index)->command)
	{
		if (_strcmp(cmd[0], (bl_deck + index)->command) == 0)
		{
			return ((bl_deck + index)->fun(cmd, er));
		}
		index++;
	}
	return (-1);
}
/**
 * read_cmd - Execute the shell using Fork, Wait, Excute
 * @cmd: Command in processing state
 * @input: Variable that takes in a command
 * @c: Shell speed checker
 * @argv: Arg variable name
 * Return: 0, 1, -1 (Executed, Null, Wrong)
 */
int read_cmd(char **cmd, char *input, int c, char **argv)
{
	int state;
	pid_t process_id;

	if (*cmd == NULL)
	{
		return (-1);
	}
	process_id = fork();
	if (process_id == -1)
	{
		perror("Error");
		return (-1);
	}
	if (process_id == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmnd(cmd);
		}
		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&state);
	return (0);
}
/**
 * interrupt_handler - The interrupter
 * @sig: The variable that waits for the call
 * Return: Void is returned
 */
void interrupt_handler(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
