#include "monty.h"
/**
 * error_func - prints error messages and the exits the program.
 * @line_number: line number of the monty file
 * @messagge: error message  given
 * Return: void (EXIT_FAILURE) exit status
 */
void error_func(char *messagge, unsigned int line_number)
{
	if (messagge == NULL)
		return;
	fprintf(stderr, "L%u: %s\n", line_number, messagge);
	exit(EXIT_FAILURE);
}
/**
 * op_pchar - prints the char at the top of the stack, followed by a new line
 * @stack: head node to the stack
 * @line_number: line number of the monty file
 * Return: void (EXIT_FAILURE) exit status
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int x = 0;

	if (*stack == NULL || stack == NULL)
		error_func("can't pchar, stack empty", line_number);
	x = (*stack)->n;
	if (x >= 1 && x <= 127)
	{
		putchar(x);
		putchar('\n');
	}
	else
	{
		error_func("can't pchar, value out of range", line_number);
	}
}
/**
 * op_pstr - prints the string starting at the top of the stack
 * @stack: head node to the stack.
 * @line_number: line number of the monty file
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	int x = 0;

	(void)line_number;
	if (*stack == NULL || stack == NULL)
		putchar('\n');
	else
	{
		ptr = *stack;
		while (ptr != NULL)
		{
			x = ptr->n;
			if (x >= 1 && x <= 127)
				putchar(x);
			else
				break;
			ptr = ptr->next;
		}
		putchar('\n');
	}
}
