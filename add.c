#include "monty.h"
/**
 * f_add - it adds the two elements
 *  at the top of the stack.
 * @head: its the head of the stack
 * @counter: line_number
 * Return: no return
 * 
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int i = 0, a;

	h = *head;
	while (h)
	{
		h = h->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	a = h->n + h->next->n;
	h->next->n = a;
	*head = h->next;
	free(h);
}

