#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024

bus_t bus = { NULL, NULL, NULL, 0 };
/**
 * main - monty code interpreter.
 * 
 * @argc: number of arguments.
 * @argv: monty file location.
 * Return: 0 on success.
 */
int main(int argc, char *argv[]) {
    char content[MAX_LINE_SIZE];
    FILE *file;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0) {
        content[0] = '\0'; /* Clear the content array*/
        if (fgets(content, MAX_LINE_SIZE, file) == NULL)
            break; /* End of file or error*/

        bus.content = content;
        counter++;

        execute(content, &stack, counter, file);
    }

    free_stack(stack);
    fclose(file);
    return 0;
}

