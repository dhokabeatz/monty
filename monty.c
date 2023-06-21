#include <stdlib.h>
#include "monty.h"
#include <stddef.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    /*Variable declarations */
    FILE *file = fopen(argv[1], "r");
    /* Initialize necessary variables and data structures */
    /* stack_t *stack = NULL;*/
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t linelen;
    unsigned int line_number = 0;

    /* Check if the correct number of arguments is provided */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty byte code file */
    
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

   

    /* Read the Monty byte code file line by line */
    while ((linelen = getline(&line, &bufsize, file)) != -1)
    {
        line_number++;
        /* Tokenize the line to extract the opcode and its argument (if any) */
        /* Process the opcode and perform the corresponding operation */
        /* Handle any errors or unknown opcodes as specified in the task */
    }

    /* Cleanup: Close the file, free memory, etc. */

    return 0;
}
