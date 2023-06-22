#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 *
 * followed by a new.
 * @head: stack head.
 * @counter: line_number.
 * Return: no return.
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *c;
	(void)counter;

	c = *head;
	while (c)
	{
		if (c->n > 127 || c->n <= 0)
		{
			break;
		}
		printf("%c", c->n);
		c = c->next;
	}
	printf("\n");
}
