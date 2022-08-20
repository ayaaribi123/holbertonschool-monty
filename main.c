#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: exit SUCCESS on success, FAILURE on fail
 */

int main(int argc, char **argv)
{
	FILE *fd;
	char *line = NULL;
	size_t size = 0;
	char *opcode = NULL;
	unsigned int line_number = 1; /* Monty starts counting lines at 1 */
	stack_t *STACK, *temp;
	(void) argc; /* temporary */

	STACK = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r"); /* open file */

	if (!fd) /* error if cannot open file - maybe using fprintf */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&line, &size, fd)) != (-1)) /* read each line */
	{
		if (*line == '\n') /* check for blank line */
		{
			line_number++;
			continue;
		}
		opcode = strtok(line, " \t\n"); /* set opcode to first token of strtok */

		if (!opcode) /* check for strtok fail */
		{
			line_number++;
			continue;
		}
		Arg.argument = strtok(NULL, " \t\n");

		execute_opcode(opcode, &STACK, line_number);
		line_number++;
	}

	free(line); /* free line */

	if (STACK != NULL) /* free stack */
	{
		while (STACK != NULL)
		{
			temp = STACK;
			STACK = temp->next;
			free(temp);
		}
	}

	fclose(fd); /* close file */

	exit(EXIT_SUCCESS); /* exit */
}
