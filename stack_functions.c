#include "monty.h"

/**
 * op_pall - Prints all elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *ptr;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

int arg = 0; 

/**
 * op_push - Pushes an element into the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void) line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	if (*stack == NULL)
		new_node->next = NULL;
	else
		new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}
/**
 * op_swap - swaps top two elements of the stack
 * @stack: doubly linked list representation of the stack
 * @line_number: Line number of the instruction
 * Return: void
 */
char swap(char **stack, unsigned int line_number)
{
    char *ptr;
    
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("Error"); //add Error fucntion
    }
    ptr = (*stack)->next;
    (*stack)->prev = ptr;
    (*stack)->next = ptr->next;
    ptr->prev = NULL;
    ptr->next = *stack;
    *stack = ptr;
}
