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
		error_func(line_number, 2);
	printf("%d\n", (*stack)->n);
}