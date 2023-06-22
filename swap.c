#include "monty.h"
/**
* f_swap - adds the top two elements the stack.
*
* @head: stack head.
* @counter: line_number.
* Return: no return.
*/
void f_swap(stack_t **head, unsigned int counter)
{
stack_t *c;
int len = 0, aux;

c = *head;
while (c)
{
c = c->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
c = *head;
aux = c->n;
c->n = c->next->n;
c->next->n = aux;
}
