#include "monty.h"
void main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    unsigned int i, line_no = 0;
    MAX_LINE_LENGTH = 1024;
    char *line;
    instruction_t struct_array[]{{"push", void push(stack_t **stack, unsigned int line_number)}};
    stack_t *_stack;
    int _arg;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file <file>");
        return EXIT_FAILURE;
    }
    while (getline(&line, &MAX_LINE_LENGTH, file))
    {
        stripped_line = remove_whitespace(line);
        for(i = 0; i < 1; i++)
        {
            if (substring(stripped_line, struct_array[i].opcode))
            {
                _arg = stripped_line[4];
                struct_array[i].f(&_stack, line_no);
            }
        }
        line_no++;
    }
    }
}