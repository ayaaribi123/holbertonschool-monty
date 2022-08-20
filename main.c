#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument value
 *
 * Return: exit SUCCESS on success, FAILURE on fail
 */

int main(int argc, char **argv)
{
	FILE *fd;
	char *line = NULL;
	size_t size = 0;
	char *opcode = NULL;
	unsigned int line_number = 1;
	stack_t *STACK, *temp;
	(void) argc;
	STACK = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &size, fd)) != (-1))
	{
		if (*line == '\n')
		{
			line_number++;
			continue;
		}
		opcode = strtok(line, " \t\n");
		if (!opcode)
		{
			line_number++;
			continue;
		}
		Arg.argument = strtok(NULL, " \t\n");
		execute_opcode(opcode, &STACK, line_number);
		line_number++;
	}
	free(line);
	if (STACK != NULL)
	{while (STACK != NULL)
		{temp = STACK;
			STACK = temp->next;
			free(temp);}}
	fclose(fd);
	exit(EXIT_SUCCESS);
}
