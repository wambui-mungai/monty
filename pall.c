#include "monty.h"
#include <stdio.h>

/**
 * f_pall - prints the stack
 * @head: stack head
 *
 * @counter: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *b;
	(void)counter;

	b = *head;
	if (b == NULL)
		return;
	while (b)
	{
		printf("%d\n", b->n);
		b = b->next;
	}
}
