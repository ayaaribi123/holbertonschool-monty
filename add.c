#include "monty.h"
/**
*add - main elements
*@stack: pointer
*@line_number: line number
*Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
	(*stack)->n += (*stack)->n;
}
