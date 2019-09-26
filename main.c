#include "monty.h"
/**
 * interpret - interprets the file (reading)
 * @file_name: file's path
 *
 * Return: void
 */

void interpret(char *file_name)
{
	stack_t *stack = NULL;
	FILE *file;
	char **tokens, *buffer = NULL;
	size_t size = 0;
	int line_number = 0;

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, file) != -1)
	{
		line_number++;
		tokens = parse_line(buffer);
		if (tokens == NULL)
			continue;
		else
			get_function(tokens, line_number)(&stack, line_number);
	}
	fclose(file);
	free(buffer);
	free_list(&stack);
}

/**
 * main - takes input from user
 * @argc: argument numbers
 * @argv: arguments recieved by user
 *
 * Return: 0 or EXIT on failure
 */

int main(int argc, char *argv[])
{
	char *file_name;

	file_name = argv[1];
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	interpret(file_name);
	return (0);
}

