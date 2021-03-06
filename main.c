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
    int buf_len = 7;
    char line[50];
    stack_t *_stack;
    instruction_t struct_array[] = {{"push", add_dnodeint}, {"pall", print_stack}};
    if (argc != 2)
    {
        usage();
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        not_file(argv[1]);
    }
    while (fgets(line, buf_len, file) != NULL)
    {
        /*printf("%s\n", line);*/
        stripped_line = remove_whitespace(line);
        /*printf("stripped line1: %s", stripped_line);*/
        for(i = 0; i < 2; i++)
        {
            if (substring(stripped_line, struct_array[i].opcode))
            {
                struct_array[i].f(&_stack, line_no);
                break;
            }
            else if (i == 1)
            {
                invalid_instruction(line_no, line);
            }
        }
        line_no++;
    }
    fclose(file);
    return (0);
}