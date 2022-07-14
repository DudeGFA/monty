#include "monty.h"
/**
 * print_dlistint - prints members of a
 * doubly linked list
 * @h: pointer to head of doubly liked list
 * Return: size_t
 */
size_t print_dlistint(const stack_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
void print_stack(stack_t **_stack, unsigned int line_no __attribute__((unused)))
{
    print_dlistint(*_stack);
}