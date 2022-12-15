#include "monty.h"
stack_t *head = NULL;
/**
*main - Entry point
*@argc: number of command line argurments
*@argv: vector arguments
*Return: Always 0
*/
int main(int argc, char **argv)
{
if (argc < 2 || argc > 2)
err(1);
open_file(argv[1]);
free_nodes();
return (0);
}
/**
*free_nodes - frees no in the stack
*/
void free_nodes(void)
{
stack_t *temp;
if (head == NULL)
return;
while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
}
/**
*create_node - populates and creates a node
*@n: data to be inserted
*Return: a ptr if success or NULL
*/
stack_t *create_node(int n)
{
stack_t *node;
node = malloc(sizeof(stack_t));
if (node == NULL)
err(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}
