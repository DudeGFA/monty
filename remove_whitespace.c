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
    printf("oldstr: %s\n", old_str);
    for(i = 0; old_str[i]; i++)
    {
        if (old_str[i] != ' ' && old_str[i] != '\t' && old_str[i] != '\n')
        {
            new_str[j] = old_str[i];
            j++;
        }
        if (j == 5)
        {
            break;
        }
        new_str[6] = '\0';
    }

    printf("new_str: %s\n", new_str);
    p = new_str;
    return p;
}