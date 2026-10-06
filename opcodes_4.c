#include "monty.h"

/**
 * f_pchar - prints the char at top of stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n < 0 || h->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * f_pstr - prints string starting at top of stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	(void)counter;

	while (h)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * f_rotl - rotates stack to top
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head, *aux;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
		return;

	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
 * f_rotr - rotates stack to bottom
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_rotr(stack_t **head, unsigned int counter)
{
	stack_t *copy = *head;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
		return;

	while (copy->next)
		copy = copy->next;

	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	*head = copy;
}

/**
 * f_stack - sets format to stack (LIFO)
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
 * f_queue - sets format to queue (FIFO)
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}
