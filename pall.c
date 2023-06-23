#include "monty.h"
#include <stdio.h>

/**
 * f_pall - prints the stack
 * @head: stack head
 *
 * @counter: no used
 * Return: no return
*/
typedef struct stack_s {
    int n;
    struct stack_s *prev;
} stack_t;

stack_t *stack = NULL;

void f_push(stack_t **head, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = *head;
    *head = new_node;
}

void f_pall(stack_t **head, unsigned int line_number) {
    stack_t *current = *head;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->prev;
    }
}

void process_opcode(unsigned int line_number, const char *opcode, const char *argument) {
    if (strcmp(opcode, "push") == 0) {
        if (argument == NULL) {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int value = atoi(argument);
        f_push(&stack, value);
    } else if (strcmp(opcode, "pall") == 0) {
        f_pall(&stack, line_number);
    } else {
        fprintf(stderr, "L%d: unknown opcode: %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

int main() {
    const char *code[][2] = {
        {"push", "1"},
        {"push", "2"},
        {"push", "3"},
        {"pall", NULL},
    };

    unsigned int num_instructions = sizeof(code) / sizeof(code[0]);

    for (unsigned int i = 0; i < num_instructions; i++) {
        const char *opcode = code[i][0];
        const char *argument = code[i][1];
        process_opcode(i + 1, opcode, argument);
    }

    return 0;
}

