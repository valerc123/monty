#include "monty.h"
/**
* parse_line - Parses a line in to tokens, only get two first tokens
* @line: line mode by user
* Return:  tokens, or NULL if failed
*/

char **parse_line(char *line)
{
	char *token, **tokens;
	unsigned int i;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");	
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

int arg = 0;
/**
 * get_function - interprets and execute functions from tokens
 * @tokens: array of strings
 * @ln: line number in monty code file
 *
 * Return: proper function or NULL
 */
void(*get_op_func(char **tokens, unsigned int ln))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"pint", op_pint},
		{"nop", op_nop},
		{"swap", op_swap},
		{"add", op_add},
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
				error_func("usage: push integer", ln);
			}
			else if ((strcmp(ops[i].opcode, "push") == 0))
				arg = atoi(tokens[1]);
			free(tokens);
			return (ops[i].f);
		}
		i++;
	}
	dprintf(STDOUT_FILENO,"L%d: unknown instruction %s\n", ln, tokens[0]);
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
