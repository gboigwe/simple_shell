#include "shell.h"
/**
 * file_check - PARSE Fork Wait then execute in the file line
 * @line: Variable to check line of file
 * @counter: Checking the counted lenght
 * @fp: Describing the file kind to print
 * @argv: Arg variable name
 * Return: Void not executable
 */
void file_check(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd_prompt;
	int stat_e = 0;

	cmd_prompt = _parse(line);

		if (_strncmp(cmd_prompt[0], "exit", 4) == 0)
		{
			exit_func_file(cmd_prompt, line, fp);
		}
		else if (check_builtin(cmd_prompt) == 0)
		{
			stat_e = builtins_handler(cmd_prompt, stat_e);
			free(cmd_prompt);
		}
		else
		{
			stat_e = read_cmd(cmd_prompt, line, counter, argv);
			free(cmd_prompt);
		}
}
/**
 * f_read - File runs after command is called
 * @filename: The filename to be called
 * @argv: The arg variable name
 *
 * Return: 0 (Success), -1 (error)
 */
void f_read(char *filename, char **argv)
{
	FILE *f_print;
	char *by_line = NULL;
	size_t count = 0;
	int count_len = 0;

	f_print = fopen(filename, "r");
	if (f_print == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&by_line, &count, f_print)) != -1)
	{
		count_len++;
		file_check(by_line, count_len, f_print, argv);
	}
	if (by_line)
	{
		free(by_line);
	}
	fclose(f_print);
	exit(0);
}
/**
 * exit_func_file - Exit Shell Case Of File
 * @line: Variable to check line of file
 * @cmd: Command in processing state
 * @fd: Describing the file kind dir
 * Return: Execute not returnable
 */
void exit_func_file(char **cmd, char *line, FILE *fd)
{
	int state = 0;
	int index = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][index])
	{
		if (_isalpha(cmd[1][index++]) < 0)
		{
			perror("wrongly inputted number");
		}
	}
	state = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(state);
}
