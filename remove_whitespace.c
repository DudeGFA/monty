#include <stdio.h>
#include "monty.h"
char *remove_whitespace(char *str)  
{
    for(i = 0; str[i]; i++)
    {
        if (str[i] == ' ' || str[i] == '\t' || sr[i] == '\n')
        {
            str[i] = str[i + 1];
            i++;
        }
    }
    return str;
}