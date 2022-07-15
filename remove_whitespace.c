#include "monty.h"
int _strlen(char *stri)
{
    int i;

    for (i = 0; stri[i]; i++)
    {
    }
    return (i);
}
char *remove_whitespace(char *old_str)  
{
    unsigned int i, j = 0;
    char new_str[7];
    char *p;

    for(i = 0; old_str[i], j < 6; i++)
    {
        if (old_str[i] != ' ' && old_str[i] != '\t' && old_str[i] != '\n')
        {
            new_str[j] = old_str[i];
            j++;
        }
    }
    p = &new_str;
    return p;
}