#include "monty.h"
/**
* f_div - Divides the second top element of
* the stack by the top element.
* @head: Pointer to the head of the stack
* @counter: line_number
* Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
stack_t *c;
int i = 0, a;

c = *head;
while (c)
{
c = c->next;
i++;
}
if (i < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
c = *head;
if (c->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
a = c->next->n / c->n;
c->next->n = a;
*head = c->next;
free(c);
}

