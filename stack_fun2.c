#include "monty.h"
/**
 * nop - does nothing
 * @stack: ptr pointing to top node
 * @line_number: int representing the line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - swaps the top 2 elements of the stack
 * @stack: ptr pointing to the top node
 * @line_number: int representing the line number of the opcode
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add_nodes - adds the top 2 elements of the stack
 * @stack: ptr pointing to top node of the stack
 * @line_number: int representing the line number of the opcode
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
