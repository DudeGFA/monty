#include "monty.h"
int _arg;
char *stripped_line;
void not_file(char * file_name)
{
        fprintf(stderr, "Error: Can't open file %s", file_name);
        return EXIT_FAILURE;
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
    unsigned int MAX_LINE_LENGTH = 1024;
    char *line;
    instruction_t struct_array[]{{"push", stack_t *add_dnodeint(stack_t **head, unsigned int line_no)}, {"pall", size_t print_dlistint(stack_t **_stack, unsigned int line_no)}};
    stack_t *_stack;

    if (argc != 2)
        usage();
    file = fopen(argv[1], "r");
    if (!file)
        not_file();
    while (getline(&line, &MAX_LINE_LENGTH, file) != (-1))
    {
        stripped_line = remove_whitespace(line);
        for(i = 0; i < 2; i++)
        {
            if (substring(stripped_line, struct_array[i].opcode))
            {
                struct_array[i].f(&_stack, line_no);
            }
            else if (i == 1)
                invalid_instruction(line_no, line);
        }
        line_no++;
    }
    return (0);
}