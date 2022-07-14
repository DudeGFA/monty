#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *stripped_line;
void not_file(char *file_name)
{
    fprintf(stderr, "Error: Can't open file %s", file_name);
    exit(EXIT_FAILURE);
}
void usage()
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}
void invalid_instruction(unsigned int line_no, char *line)
{
    fprintf(stderr, "L%i: unknown instruction %s", line_no, line);
    exit(EXIT_FAILURE);
}
int main(int argc, char *argv[])
{
    FILE *file;
    unsigned int i, line_no = 1;
    size_t buf_len = 0;
    char *line = NULL;
    stack_t *_stack;
    instruction_t struct_array[] = {{"push", add_dnodeint}, {"pall", print_dlistint}};

    if (argc != 2)
        usage();
    file = fopen(argv[1], "r");
    if (!file)
        not_file(argv[1]);
    while ((getline(&line, &buf_len, file)) >= 0)
    {
        stripped_line = remove_whitespace(line);
        for(i = 0; i < 2; i++)
        {
            if (substring(stripped_line, struct_array[i].opcode))
            {
                struct_array[i].f(&_stack, line_no);
                break;
            }
            else if (i == 1)
                invalid_instruction(line_no, line);
        }
        line_no++;
    }
    free(line);
    fclose(file);
    return (0);
}