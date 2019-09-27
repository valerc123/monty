#include "monty.h"
/**
* error_free - frees in error case
*
* @stack: pointer to head
*
* Return: no return
*/
void error_free(stack_t *stack)
{
	if (global.line)
	{
		free(global.line);
	}
	if (global.filenm)
	{
		free(global.filenm);
	}
	free(stack);
}
/**
 * op_mul - multiplies the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func("can't mul, stack too short", line_number);
		error_free(*stack);
	}
	ptr = *stack;
	if (ptr->next == NULL)
		error_func("can't mul, stack too short", line_number);
	ptr->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
/**
 * op_div - divides the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func("can't div, stack too short", line_number);
		error_free(*stack);
	}
	ptr = *stack;
	if (ptr->n == 0)
		error_func("division by zero", line_number);
	if (ptr->next == NULL)
		error_func("can't div, stack too short", line_number);
	ptr->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}

/**
 * op_mod - mods the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func("can't mod, stack too short", line_number);
		error_free(*stack);
	}
	ptr = *stack;
	if (ptr->n == 0)
		error_func("division by zero", line_number);
	if (ptr->next == NULL)
		error_func("can't mod, stack too short", line_number);
	ptr->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
/**
 * op_sub - subtracts the n value of the top two node, then pops.
 * @stack: doubly linked list representation of the stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		error_func("can't sub, stack too short", line_number);
		error_free(*stack);
	}
	ptr = *stack;
	if (ptr->next == NULL)
		error_func("can't sub, stack too short", line_number);
	ptr->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
