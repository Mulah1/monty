#include "monty.h"
#include <string.h>

int is_integer(const char *str)
{
    if (!str)
        return (0);
    if (*str == '+' || *str == '-')
        str++;
    if (!*str)
        return (0);
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

void push(stack_t **stack, int n)
{
    stack_t *node = malloc(sizeof(stack_t));

    if (!node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->n = n;
    node->prev = NULL;
    node->next = *stack;
    if (*stack)
        (*stack)->prev = node;
    *stack = node;
}

void pall(const stack_t *stack)
{
    const stack_t *tmp = stack;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

void free_stack(stack_t *stack)
{
    stack_t *tmp;

    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    while ((read = getline(&line, &len, fp)) != -1)
    {
        char *op;
        char *arg;
        stack_t *tmp;

        line_number++;
        op = strtok(line, " \t\n");
        if (!op || op[0] == '#')
            continue;

        if (strcmp(op, "push") == 0)
        {
            arg = strtok(NULL, " \t\n");
            if (!is_integer(arg))
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            push(&stack, atoi(arg));
        }
        else if (strcmp(op, "pall") == 0)
            pall(stack);
        else if (strcmp(op, "pint") == 0)
        {
            if (!stack)
            {
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            printf("%d\n", stack->n);
        }
        else if (strcmp(op, "pop") == 0)
        {
            if (!stack)
            {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            tmp = stack;
            stack = stack->next;
            if (stack)
                stack->prev = NULL;
            free(tmp);
        }
        else if (strcmp(op, "swap") == 0)
        {
            if (!stack || !stack->next)
            {
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            tmp = stack;
            stack = stack->next;
            tmp->next = stack->next;
            if (stack->next)
                stack->next->prev = tmp;
            stack->prev = NULL;
            stack->next = tmp;
            tmp->prev = stack;
            if (stack == NULL)
                ;
        }
        else if (strcmp(op, "add") == 0)
        {
            if (!stack || !stack->next)
            {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            stack->next->n += stack->n;
            tmp = stack;
            stack = stack->next;
            stack->prev = NULL;
            free(tmp);
        }
        else if (strcmp(op, "nop") == 0)
            ;
        else if (strcmp(op, "sub") == 0)
        {
            if (!stack || !stack->next)
            {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            stack->next->n -= stack->n;
            tmp = stack;
            stack = stack->next;
            stack->prev = NULL;
            free(tmp);
        }
        else if (strcmp(op, "div") == 0)
        {
            if (!stack || !stack->next)
            {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (stack->n == 0)
            {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            stack->next->n /= stack->n;
            tmp = stack;
            stack = stack->next;
            stack->prev = NULL;
            free(tmp);
        }
        else if (strcmp(op, "mul") == 0)
        {
            if (!stack || !stack->next)
            {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            stack->next->n *= stack->n;
            tmp = stack;
            stack = stack->next;
            stack->prev = NULL;
            free(tmp);
        }
        else if (strcmp(op, "mod") == 0)
        {
            if (!stack || !stack->next)
            {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            if (stack->n == 0)
            {
                fprintf(stderr, "L%u: division by zero\n", line_number);
                free(line);
                free_stack(stack);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
            stack->next->n %= stack->n;
            tmp = stack;
            stack = stack->next;
            stack->prev = NULL;
            free(tmp);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
            free(line);
            free_stack(stack);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    free_stack(stack);
    fclose(fp);
    return (EXIT_SUCCESS);
}
