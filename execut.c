#include "monty.h"
#define OPCODES             \
	{                       \
		{"push", push},     \
			{"pall", pall}, \
			{"pint", pint}, \
			{"pop", pop},   \
			{"swap", swap}, \
			{"add", add},   \
			{"nope", nope}, \
		{                   \
			NULL, NULL      \
		}                   \
	}
/**
 * execute_opcode - call opcode of every function
 * @opcode: opcode that will be passed to function
 * @stack: pointer to the stack
 * @line_number: line numbers
 *
 */

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t opcodes[] = OPCODES;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
	
}
