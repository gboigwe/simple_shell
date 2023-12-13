#include "shell.h"

/**
 * _prompt - Display shell prompt
 */
void _prompt(void)
{
    PRINTER("$ ");
}

/**
 * print_error - Display error based on command and loop count
 * @input: User input
 * @counter: Simple shell loop count
 * @argv: Program name
 *
 * Return: void
 */
void print_error(char *input, int counter, char **argv)
{
    char *er;

    PRINTER(argv[0]);
    PRINTER(": ");
    
    er = _itoa(counter);
    if (er)
    {
        PRINTER(er);
        free(er);
    }

    PRINTER(": ");
    PRINTER(input);
    PRINTER(": not found\n");
}
