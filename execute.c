#include "monty.h"
/**
* execute - executes the opcode.
* @stack: head linked list-stack
* @counter: line_counter.
* @file: poiner to monty file.
* @content: line content.
* Return: no return.
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int a = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[a].opcode && op)
	{
		if (strcmp(op, opst[a].opcode) == 0)
		{	opst[a].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
