#include "monty.h"

/**
 * free_stack - frees a doubly linked list stack
 * @head: pointer to top of stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * is_number - checks if a string is a valid integer number
 * @str: string to check
 *
 * Return: 1 if number, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[0] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
