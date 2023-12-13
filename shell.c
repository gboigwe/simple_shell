#include "shell.h"
/**
 * main - The Simple Shell(Hsh)
 * @argc: The arg count considered
 * @argv: The arg variable considered
 * Return: Code is running
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *data_var, **comand;
	int nums = 0, state = 1, str = 0;

	if (argv[1] != NULL)
		f_read(argv[1], argv);
	signal(SIGINT, interrupt_handler);
	while (state)
	{
		nums++;
		if (isatty(STDIN_FILENO))
			_prompt();
		data_var = _readinput();
		if (data_var[0] == '\0')
		{
			continue;
		}
		hist(data_var);
		comand = _parse(data_var);
		if (_strcmp(comand[0], "exit") == 0)
		{
			exit_func(comand, data_var, argv, nums);
		}
		else if (check_builtin(comand) == 0)
		{
			str = builtins_handler(comand, str);
			free_array(comand, data_var);
			continue;
		}
		else
			str = read_cmd(comand, data_var, nums, argv);
		free_array(comand, data_var);
	}
	return (state);
}
/**
 * check_builtin - Checks for the builtin function
 *
 * @cmd: Variable command checker
 * Return: 0 Success
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int index = 0;

	if (*cmd == NULL)
		return (-1);
	while ((fun + index)->command)
	{
		if (_strcmp(cmd[0], (fun + index)->command) == 0)
			return (0);
		index++;
	}
	return (-1);
}
/**
 * creat_envi - Creation of array environment variable
 * @envi: Environment variable array
 * Return: Void
 */
void creat_envi(char **envi)
{
	int index;

	for (index = 0; environ[index]; index++)
		envi[index] = _strdup(environ[index]);
	envi[index] = NULL;
}
