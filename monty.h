#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - global variables wrapper
 * @arg: string value argument for push
 * @file: pointer to monty bytecode file
 * @content: line content buffer
 *
 * Description: variables shared across functions
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
} bus_t;

extern bus_t bus;

/* Helper & Core Functions */
void free_stack(stack_t *head);
int execute(char *content, stack_t **stack, unsigned int line_number, FILE *file);
int is_number(char *str);

/* Opcode Functions */
void f_push(stack_t **head, unsigned int line_number);
void f_pall(stack_t **head, unsigned int line_number);
void f_pint(stack_t **head, unsigned int line_number);
void f_pop(stack_t **head, unsigned int line_number);
void f_swap(stack_t **head, unsigned int line_number);
void f_add(stack_t **head, unsigned int line_number);
void f_nop(stack_t **head, unsigned int line_number);
void f_sub(stack_t **head, unsigned int line_number);
void f_div(stack_t **head, unsigned int line_number);
void f_mul(stack_t **head, unsigned int line_number);
void f_mod(stack_t **head, unsigned int line_number);

#endif /* MONTY_H */
