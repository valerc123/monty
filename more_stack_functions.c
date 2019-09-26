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
		error_func("can't pint, stack empty", line_number);
	printf("%d\n", (*stack)->n);
}
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
	dprintf(STDOUT_FILENO, "L%u: %s\n", line_number, messagge);
	exit(EXIT_FAILURE);
}
/**
 * op_pop - Removes stacks top element
 * @stack: our stack
 * @line_number: instruction number
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
		error_func("can't pop an empty stack", line_number);

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		ptr = (*stack)->next;
		(*stack) = ptr;
		ptr = ptr->prev;
		(*stack)->prev = NULL;
		free(ptr);
	}
}
