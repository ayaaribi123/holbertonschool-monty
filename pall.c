#include "monty.h"

/**
 *pall - print all the values on the stack, start from the top of the stack
 *@stack: pointer to the stack
 *@line_number:line number
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int lengeth = 0;
	(void)line_number;
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		++lengeth;
		*stack = (*stack)->next;
	}
}
