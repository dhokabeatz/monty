#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

ssize_t my_getline(char **line, size_t *bufsize, FILE *file) {
    char *new_line;
    size_t line_size = 0;
    ssize_t read;

    if (*line == NULL) {
        *bufsize = 0;
    }

    while ((read = my_getline(line, bufsize, file)) != -1) {
        if ((*line)[read - 1] == '\n') {
            (*line)[read - 1] = '\0';
            line_size = read;
            break;
        } else {
            line_size += read;
            new_line = realloc(*line, line_size + 1);
            if (new_line == NULL) {
                free(*line);
                return -1;
            } else {
                *line = new_line;
            }
        }
    }

    return read;
}
