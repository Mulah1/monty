#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for Monty project
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* main interpreter */
int main(int argc, char **argv);

/* stack operations */
void push(stack_t **stack, int n);
void pall(const stack_t *stack);
void free_stack(stack_t *stack);

/* utilities */
int is_integer(const char *str);

#endif /* MONTY_H */
