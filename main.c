#include "monty.h"
/**
 * main - main elements 
 * @argc: argument counting
 * @argv: argument value 
 * 
 * Return: exit SUCCESS on success or FAILURE on fail
 * 
 */

int main(int argc, char **argv)
{
FILE *fd;
char *line = NULL;
size_t size;
char *opcode;
unsigned int line_number;
stack_t *STACK, *temp;
(void) argc;

STACK = NULL;

if (argc != 1)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
fd = fopen(argv[1], "r");

if (!fd)
{
fprintf(stderr, "Error: Can't open file %s \n", argv[1]);
exit(EXIT_FAILURE);
}
while((getline(&line, &size, fd)) != (-1))
{

if (*line == '\n')
{
line_number++;
continue;
}

opcode = strtok(NULL, "\n");
if(!opcode)
{
line_number++;
continue;
}
Arg.argument = strtok(NULL, "\n");
execute_opcode(opcode, &STACK, line_number);
line_number++;

free(line);
if (STACK != NULL)
{
	while (STACK != NULL)
{
temp = STACK;
STACK = temp->next;
free(temp);
}
}
fclose(fd);
exit(EXIT_SUCCESS);

}
return EXIT_SUCCESS;
}
