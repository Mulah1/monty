#include "monty.h"

/**
 * f_push - pushes an element onto the stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n;
	stack_t *new_node;

	if (!bus.arg || !is_number(bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * f_pall - prints all elements of the stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	(void)counter;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * f_pint - prints the value at the top of the stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * f_pop - removes the top element of the stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	if (*head)
		(*head)->prev = NULL;
	free(h);
}
