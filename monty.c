#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "monty.h"

int is_number(const char *str)
{
    int i = 0; /* Move the variable declaration to the beginning of the block */

    if (str == NULL || *str == '\0')
        return 0;

    if (str[0] == '-' || str[0] == '+')
        i = 1;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}


void pall(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *temp;
    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *stack = NULL;
}

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t linelen;
    unsigned int line_number = 0;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((linelen = getline(&line, &bufsize, file)) != -1)
    {
        char *line_copy = strdup(line); /* Copy line for error messages */
        char *opcode;
        char *arg;
        line_number++;
        
        

        if (line_copy == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }

        opcode = strtok(line_copy, " \t\n");
        if (opcode == NULL || opcode[0] == '#')
        {
            free(line_copy);
            continue;
        }

        if (strcmp(opcode, "push") == 0)
        {
             int value = atoi(arg);
            arg = strtok(NULL, " \t\n");
            if (arg == NULL || !is_number(arg))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(line_copy);
                exit(EXIT_FAILURE);
            }

            /* Move the variable declaration to the beginning of the block */
           

            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line_copy);
            exit(EXIT_FAILURE);
        }

        free(line_copy);
    }

    free_stack(&stack);
    free(line);
    fclose(file);

    return 0;
}
