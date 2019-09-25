#include "monty.h"
char **parse_line(char *line)
{
	char *token;
	char **tokens;
	int i;

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
	while (token != NULL )
	{
		tokens[i] = token;
		token = strtok(NULL, " '\n'");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
