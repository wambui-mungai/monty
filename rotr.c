#include "monty.h"
/**
  *f_rotr- rotates the stack by moving 
  the bottom element to the top,
 * shifting all other elements down.
  *@head: Pointer to the head of the stack
  *@counter: line_number
  *Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *cp;

	cp= *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (cp->next)
	{
		cp = cp->next;
	}
	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}

