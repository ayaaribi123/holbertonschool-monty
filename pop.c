#include "monty.h"
/**
*pop - main elements
*@stack: pointer
*@line_number: line number
*Return: exit SUCCESS on success or FAILURE on fail
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t n;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = *stack;
	*stack = (*stack)->next;
  free(n);
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	return(*stack);
}
