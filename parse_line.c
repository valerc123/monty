#include "monty.h"
/**
* parse_line - Parses a line in to tokens, only get two first tokens
* @line: string to tokenize
* Return: double pointer of tokens, or NULL if failed
*/
char **parse_line(char *line)
{
	char *token;
	char **tokens;
	unsigned int i;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " '\n'");
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	i = 0;
	while (token != NULL && i < 2)
	{
		tokens[i] = token;
		token = strtok(NULL, " '\n'");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
