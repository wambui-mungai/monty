#include "monty.h"
/**
  *f_rotl- rotates the stack by moving the 
  top element to the bottom and so on

  *@head: Pointer to the head of the stack
  *@counter: line_number
  *Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *h, *a;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	a = (*h)->next;
	a->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = temp;
	(*h) = a;
}

