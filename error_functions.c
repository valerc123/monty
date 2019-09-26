#include "monty.h"

/**
 * error_func - prints error messages and exits
 * @line_number: line number
 * @error_number: error number given from op function
 * Return: void (EXIT_FAILURE) exit status
 */
void error_func(unsigned int line_number, int error_number)
{
	if (error_number == 1)
		printf("L%d: usage: push integer", line_number);
	else if (error_number == 2)
		printf("L%d: can't pint, stack empty\n", line_number);
	else if (error_number == 3)
		printf("L%d: can't pop an empty stack\n", line_number);
	else if (error_number == 4)
		printf("L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
