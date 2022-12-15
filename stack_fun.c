#include "monty.h"
/**
 * pop_top - adds a node to the stack
 * @stack: ptr to top node of the stack
 * @line_number: int representing the line number of the opcode
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 *print_top - prints the top node of the stack
 *@stack: ptr pointing to top node of the stack
 *@line_number: int representing the line number of the opcode
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **newnode, __attribute__((unused))unsigned intln)
{
	stack_t *temp;
	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	temp = head;
	head = *newnode;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_stack - prints node to the stack
 * @stack: ptr pointing to the node
 * @line_number: int representing the line number of the opcode
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
