#include "monty.h"
/**
 * op_nop - doesnt do anything
 * @stack: our stack
 * @line_number: instruction number
 * Return: void
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * op_pint - Prints stacks top value
 * @stack: our stack
 * @line_number: instruction number
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_func("can't pint, stack empty",line_number);
	printf("%d\n", (*stack)->n);
}

void error_func(char *messagge, unsigned int line_number)
{
    	if (!messagge)
		return;
	dprintf(STDOUT_FILENO,"L%u: %s\n",line_number, messagge);
}
