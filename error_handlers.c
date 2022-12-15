#include "monty.h"
/**
 *err - prints error messages
 *@error_code: error codes:
 * (1) -> user does not give any file or more than one args
 * (2) -> for any reason its not possible to open the file
 * (3) -> the file contains an invalid instruction
 * (4) -> can't malloc anymore
 * (5) -> if int is not an integer or no arg given to push
 */
void err(int error_code, ...)
{
	va_list ap;
	char *op;
	int l_num;

	va_start(ap, error_code);
	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
					va_arg(ap, char *));
			break;
		case 3:
			l_num = va_arg(ap, int);
			op = va_arg(ap, char *);
			printf("L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(ap, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 *more_err - handles error
 *@error_code: code error:
 * (6) -> stack is empty for pint
 * (7) -> stack is empty for pop
 * (8) -> stack is too short for operation
 */
void more_err(int error_code, ...)
{
	va_list ap;
	char *op;
	int l_num;

	va_start(ap, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n",
					va_arg(ap, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
					va_arg(ap, int));
			break;
		case 8:
			l_num = va_arg(ap, unsigned int);
			op = va_arg(ap, char *);
			printf("L%d: can't %s, stack too short\n", l_num, op);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
