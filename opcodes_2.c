#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int temp;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}

/**
 * f_add - adds the top two elements of the stack
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h->next->n += h->n;
	*head = h->next;
	(*head)->prev = NULL;
	free(h);
}

/**
 * f_nop - does nothing
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
}

/**
 * f_sub - subtracts top element from second top element
 * @head: double pointer to stack head
 * @counter: line number
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h->next->n -= h->n;
	*head = h->next;
	(*head)->prev = NULL;
	free(h);
}
