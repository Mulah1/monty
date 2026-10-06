#include "monty.h"

/**
 * f_push - pushes an element onto the stack or queue
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n;

	if (!bus.arg || !is_number(bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
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
 * f_pint - prints the value at top of stack
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
 * f_pop - removes top element of stack
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
