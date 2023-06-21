#ifndef STACK_H
#define STACK_H

/* Structure for stack node */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Function prototypes */
void push(stack_t **stack, int value);
int pop(stack_t **stack);
int is_empty(stack_t *stack);

#endif /* STACK_H */
