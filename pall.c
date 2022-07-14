#include "monty.h"
/**
 * print_dlistint - prints members of a
 * doubly linked list
 * @h: pointer to head of doubly liked list
 * Return: size_t
 */
void print_dlistint(stack_t **_stack, unsigned int line_no __attribute__((unused)))
{
    stack_t *h = *_stack;
	while (h != NULL)
	{
		printf("%d\n", (*h).n);
		h = h->next;
	}
}