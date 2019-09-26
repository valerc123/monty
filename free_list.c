#include "monty.h"
/**
 * free_list - free list
 * @stack: pointer to head node
 * Return: void
 */
void free_list(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		if (temp == NULL)
			return;
		temp->prev = NULL;
		*stack = temp;
	}
	free(*stack);
}
