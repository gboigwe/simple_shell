#include "shell.h"
/**
 * pr_error - Print custom error message
 * @argv: Program name
 * @c: Error count
 * @cmd: Command
 *
 * Return: void
 */
void pr_error(char **argv, int c, char **cmd)
{
	char *er = _itochar(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");

	free(er);
}
