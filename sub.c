#include "monty.h"
/**
*f_sub- Subtracts the top element of the
stack from the second top element
*@head: Pointer to the head of the stack
*@counter: line_number
*Return: no return
*/
void f_sub(stack_t **head, unsigned int counter)
{
stack_t *a;
int i, n;

a = *head;
for (nodes = 0; a != NULL; n++)
a = a->next;
if (n < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
a = *head;
i = a->next->n - a->n;
aux->next->n = i;
*head = a->next;
free(a);
}

