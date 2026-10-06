#include "monty.h"

/**
 * f_div - divides second top element by top element
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h->next->n /= h->n;
	*head = h->next;
	(*head)->prev = NULL;
	free(h);
}

/**
 * f_mul - multiplies second top element with top element
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h->next->n *= h->n;
	*head = h->next;
	(*head)->prev = NULL;
	free(h);
}

/**
 * f_mod - computes remainder of division of second top element by top element
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h->next->n %= h->n;
	*head = h->next;
	(*head)->prev = NULL;
	free(h);
}
