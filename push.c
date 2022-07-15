#include "monty.h"
/**
 * add_dnodeint - adds a new node at
 * the beginning of a stack_t list
 * @head: pointer to head of stack_t
 * @n: value of new node
 * Return: size_t
 */
void no_int_arg_err(unsigned int line_no)
{
    printf("L%i: usage: push integer\n", line_no);
    exit(EXIT_FAILURE);
}

void add_dnodeint(stack_t **head, unsigned int line_no)
{
	stack_t *new_head_node;
	int new_arg = 1;

	printf("stripped_line: %s\n", stripped_line);
    if (_strlen(stripped_line) < 5)
	{
        no_int_arg_err(line_no);
	}
    if (!isdigit(stripped_line[4]))
	{
        no_int_arg_err(line_no);
	}
    new_arg = atoi(&(stripped_line[4]));
	/*printf("after atoi\n");
	printf("%d\n", new_arg);
	printf("new_arg check");*/
	new_head_node = malloc(sizeof(stack_t));
	if (new_head_node == NULL)
    {
		fprintf(stderr, "Error: malloc failed");
        exit (EXIT_FAILURE);
    }
	new_head_node->n = new_arg;
	new_head_node->prev = NULL;
	new_head_node->next = *head;
	if ((*head) != NULL)
	{
		(*head)->prev = new_head_node;
	}
	*head = new_head_node;
	printf("ok");
}