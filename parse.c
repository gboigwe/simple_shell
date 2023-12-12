#include "shell.h"

/**
 * _parse- Parse line of input into an array of tokens
 * @input: User input to parse
 *
 * Return: Array of strings (parsed tokens) or NULL on failure
 */
char **_parse(char *input)
{
  char **tokens;
  char *token;
  int i, buffsize = BUFSIZE;

     if (input == NULL)
        return (NULL);
    tokens = malloc(sizeof(char *) * buffsize);
        if (!tokens)
	    {
              perror("hsh");
	      return (NULL);
	    }

	    token = _strtok(input, "\n ");
	    for (i = 0; token; i++)
 	    {
	   tokens[i] = token;
	   token = _strtok(NULL, "\n ");
	    }
		   tokens[i]
		 return (tokens);
}

