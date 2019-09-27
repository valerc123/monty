#include "monty.h"
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
		error_func("can't mul, stack too short", line_number);
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
		error_func("can't div, stack too short", line_number);
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
		error_func("can't mod, stack too short", line_number);
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
		error_func("can't sub, stack too short", line_number);
	ptr = *stack;
	if (ptr->next == NULL)
		error_func("can't sub, stack too short", line_number);
	ptr->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(ptr);
	(*stack)->prev = NULL;
}
/**
 * op_add - adds the n value
 * @stack: our stack
 * @line_number: line instruction
 * Return: void
 */
void op_add(stack_t **stack, unsigned int line_number)
{
        stack_t *ptr;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                error_func("can't add, stack too short", line_number);
        }
        ptr = *stack;
        if (ptr->next == NULL)
                error_func("can't add, stack too short", line_number);
        ptr->next->n += (*stack)->n;
        *stack = (*stack)->next;
        free(ptr);
        (*stack)->prev = NULL;
}
