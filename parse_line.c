#include "monty.h"


/**
 * parse_line - interprets and execute functions from tokens
 * @line: line made by user
 *
 * Return: tokens
 */


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
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " '\n'");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}


/**
 * get_function - interprets and execute functions from tokens
 * @tokens: array of strings
 * @ln: line number in monty code file
 *
 * Return: proper function or NULL
 */


void(*get_function(char **tokens, unsigned int ln))(stack_t **, unsigned int)
{
instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"pint", op_pint},
		{"nop", op_nop},
		{"swap", op_swap},
		{NULL, NULL}
	};
	unsigned int i = 0;

	if (tokens[0][0] == '#')
	{
		free(tokens);
		return (op_nop);
	}
	while (ops[i].opcode != NULL)
	{
		if ((strcmp(ops[i].opcode, tokens[0]) == 0))
		{
			if ((strcmp(ops[i].opcode, "push") == 0) &&
			(tokens[1] == NULL || (!(valid_arg(tokens[1])))))
			{
				free(tokens);
				printf("L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
			else if ((strcmp(ops[i].opcode, "push") == 0))
				arg = atoi(tokens[1]);
			free(tokens);
			return (ops[i].f);
		}
	i++;
	}
	printf("L%d: unknown instruction %s\n", ln, tokens[0]);
	free(tokens);
	exit(EXIT_FAILURE);

}

/**
 * valid_arg - checks for a token validity
 * @token: argument token from valid_op.
 *
 * Return: 1 if valid argument, 0 if not
 */
int valid_arg(char *token)
{
	unsigned int i;

	if (token == NULL)
		return (1);
	i = 0;
	while (token[i] != '\0')
	{
		if (token[0] == '-')
		{
			if ((!(token[1] >= '0' && token[1] <= '9')) || token[1] == '\0')
				return (0);
			i = 1;
			while (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				if (token[i] == '\0')
					return (1);
			}
			return (0);
		}
		else
		{
			i = 0;
			while (token[i] >= '0' && token[i] <= '9')
			{
				i++;
				if (token[i] == '\0')
					return (1);
			}
			return (0);
		}
	}
	return (0);
}
