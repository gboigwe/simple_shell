#ifndef _SHELL_H_
#define _SHELL_H_

/**###### environ var ######*/

extern char **environ;

/**##### MACROS ######*/

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/**###### LIBS USED ######*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/**###### STRING FUNCTION ######*/

char *_strtok(char *str, const char *tok);
unsigned int delim_checker(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void opp_arr(char *arr, int len);
int numslen(int num);
char *_itochar(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/**###### MEMORIE  MANGMENT ####*/

void env_done(char **env);
void *fill_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *mem_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_array(char **input, char *line);

/**###### INPUT Function ######*/

void _prompt(void);
void interrupt_handler(int sig);
char *_readinput(void);

/** ###### Command parser and extractor ###*/

int path_cmnd(char **line);
char *get_env(char *name);
char **_parse(char *cmd);
int builtins_handler(char **cmd, int er);
void f_read(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_envi(char **envi);
int read_cmd(char **tokens, char *line, int count, char **argv);
void file_check(char *line, int counter, FILE *fd, char **argv);
void exit_func_file(char **cmd, char *line, FILE *fd);

/** ####BUL FUNC #####*/

void _hashtag(char *buff);
int hist(char *input);
int display_hist(char **cmd, int er);
int env_var(char **cmd, int er);
int dir_func(char **cmd, int er);
int help_call(char **cmd, int er);
int echo_func(char **cmd, int er);
void  exit_func(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** ####error handle and Printer ####*/
void numprint_func(unsigned int n);
void numprintin_func(int n);
void print_error(char *line, int c, char **argv);
void pr_error(char **argv, int c, char **cmd);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
