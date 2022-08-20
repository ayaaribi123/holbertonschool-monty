#include "monty.h"
/**
*swap - main elements
*@stack: pointer
*@line_number: line number
*Return: new node value
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if ((*stack) != NULL && (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
	}
	t = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = t;
	if (t->next)
	{
		t->next->prev = (*stack)->next;
		t->next = (*stack)->next;
		(*stack) = (*stack)->prev;
	}
}
