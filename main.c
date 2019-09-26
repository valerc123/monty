#include "monty.h"
/**
 * readfile - interprets the file (reading)
 * @filename: file's path
 *
 * Return: void
 */

void readfile(char *filename)
{
	stack_t *stack = NULL;
	int line_number = 0;
	char **tokens, *buffer = NULL;
	size_t size = 0;
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &size, file))
	{
		line_number++;
		tokens = parse_line(buffer);
		if (tokens == NULL)
			continue;
		else
			get_op_func(tokens, line_number)(&stack, line_number);
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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readfile(file_name);
	return (0);
}
