#include "stack.h"
#include <stdlib.h>

void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        /* Handle malloc failure */
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

int pop(stack_t **stack)
{
    if (*stack == NULL)
    {
        /* Handle empty stack */
        fprintf(stderr, "Error: cannot pop from an empty stack\n");
        exit(EXIT_FAILURE);
    }

    int value = (*stack)->n;
    stack_t *temp = *stack;

    *stack = (*stack)->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
    return value;
}

int is_empty(stack_t *stack)
{
    return stack == NULL;
}
