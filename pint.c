#include "monty.h"
/**
*pint - main elements
*@stack: pointer
*@line_number: line number
*Return: exit SUCCESS on success or FAILURE on fail
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
