
#include "monty.h"
/**
 * f_pchar - prints the char at the top of stack
 *
 * followed by new line
 * @head: stack head.
 * @counter: line_number.
 * Return: no return.
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *c;

	h = *head;
	if (!c)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (c->n > 127 || c->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c->n);
}
